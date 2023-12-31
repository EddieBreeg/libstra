
if(TARGET libstra::libstra)
    return()
endif(TARGET libstra::libstra)


file(GLOB LIBSTRA_LIB_FILE ${CMAKE_CURRENT_LIST_DIR}/../*libstra.*)

add_library(libstra::libstra STATIC IMPORTED)
set_target_properties(libstra::libstra PROPERTIES
IMPORTED_LOCATION ${LIBSTRA_LIB_FILE}
INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}/../../include
)
target_include_directories(libstra::libstra INTERFACE ${CMAKE_CURRENT_LIST_DIR}/../../include)

if(NOT DEFINED FIND_Libstra_QUIETLY)
message("Found libstra at ${CMAKE_CURRENT_LIST_DIR}")    
endif(NOT DEFINED FIND_Libstra_QUIETLY)
