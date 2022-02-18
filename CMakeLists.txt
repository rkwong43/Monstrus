cmake_minimum_required (VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(PROJECT_NAME "Monstrus")
project(${PROJECT_NAME} VERSION 0.1 LANGUAGES CXX)


# SDL2
# Probably can clean up instead of having a bunch of the source code in extern but it's easier to run for people who download it
# FetchContent works as well but it does take a bit to run every time. This is probably better for now
file(GLOB SDL2_PATH CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/extern/SDL2-*")
if (${SDL2_PATH} STREQUAL "")
    message("SDL2 not found in extern/SDL2-*...")
endif()
find_package(SDL2 REQUIRED)
file(GLOB SDL2_DIR CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/extern/SDL2_image-*")
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIRS})

# Catch2
enable_testing()
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

include(CTest)

add_subdirectory("src")
add_subdirectory("utils")
add_subdirectory("test")

# Setting up main executable
add_executable(${PROJECT_NAME} main.cpp "${SDL2_INCLUDE_DIR}/SDL.h")
#target_compile_options(${PROJECT_NAME} PRIVATE "-Wall")
target_link_libraries(${PROJECT_NAME} PRIVATE
    controller
    model
    view
    entities
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
)

# Copying DLL over into directory of executable
add_custom_command( TARGET ${PROJECT_NAME} 
                    PRE_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2_PATH}/lib/x64/SDL2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)

set(MAIN_INCLUDE_DIRS 
    "${CMAKE_SOURCE_DIR}/src/entities/include"
    "${CMAKE_SOURCE_DIR}/src/model/include" 
    "${CMAKE_SOURCE_DIR}/src/view/include"
    "${CMAKE_SOURCE_DIR}/src/controller/include" 
)

target_include_directories(${PROJECT_NAME} PUBLIC ${MAIN_INCLUDE_DIRS})