file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/entities/src/*.cpp")
add_library(entities ${SOURCE_LIST})

set(INCLUDE_PATHS
    "${CMAKE_SOURCE_DIR}/src/entities/include"
)

target_include_directories(entities PUBLIC ${INCLUDE_PATHS})