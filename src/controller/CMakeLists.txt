file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/controller/src/*.cpp")
add_library(controller ${SOURCE_LIST})

set(INCLUDE_PATHS
    "${CMAKE_SOURCE_DIR}/src/controller/include" 
    "${CMAKE_SOURCE_DIR}/src/model/include" 
    "${CMAKE_SOURCE_DIR}/src/view/include"
)

target_include_directories(controller PUBLIC ${INCLUDE_PATHS})
