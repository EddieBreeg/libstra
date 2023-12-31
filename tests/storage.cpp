#include <libstra/storage.hpp>
#include <assert.h>
#include <iostream>

struct A {
	int x;
	A() = delete;
	constexpr A(int x) : x(x) {}
	constexpr A &operator=(const A &other) noexcept {
		x = other.x;
		return *this;
	}
	~A() = default;
};

struct B {
	constexpr B(){};
	B(const B &) = delete;
	constexpr B(B &&) {}
};
struct C {
	constexpr C(int, const char *) {}
	constexpr C(std::initializer_list<int>, nullptr_t) {}
	~C() = default;
};

void constexpr_tests() {
	constexpr libstra::storage<int> s = 1;
	constexpr auto s2 = s;
	static_assert(*s2 == 1, "constexpt test failed");
	static_assert(s == s2, "constexpt test failed");
	constexpr libstra::storage<C> s3(libstra::in_place_t{}, { 1, 2 }, nullptr);
}

int main() {
	constexpr_tests();
	libstra::storage<A> s1;
	static_assert(std::is_trivially_destructible<decltype(s1)>::value,
				  "constexpt test failed");
	s1 = A(1);
	decltype(s1) s2 = 2;
	static_assert(noexcept(s1.swap(s2)), "nothrow storage swap test failed");
	s1.swap(s2);
	assert(s1->x == 2);
	assert(s2->x == 1);
}