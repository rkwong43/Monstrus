file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/view/src/*.cpp")
add_library(view ${SOURCE_LIST})

target_include_directories(view PUBLIC "${CMAKE_SOURCE_DIR}/src/view/include")
target_link_libraries(view PUBLIC entities utils)