file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/model/src/*.cpp")
add_library(model ${SOURCE_LIST})

target_include_directories(model PUBLIC "${CMAKE_SOURCE_DIR}/src/model/include")
target_link_libraries(model PUBLIC entities utils)