file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/controller/src/*.cpp")
add_library(controller ${SOURCE_LIST})

target_include_directories(controller PUBLIC "${CMAKE_SOURCE_DIR}/src/controller/include")
target_link_libraries(controller PUBLIC model view)
