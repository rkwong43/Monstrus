file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/utils/src/*.cpp")
add_library(utils ${SOURCE_LIST})

target_include_directories(utils PUBLIC "${CMAKE_SOURCE_DIR}/utils/include")

# Tests
add_subdirectory(test)