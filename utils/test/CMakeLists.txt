# Utils testing executable
add_executable(utilsTests utilsTests.cpp)
target_link_libraries(utilsTests PRIVATE Catch2::Catch2WithMain utils)

add_test(NAME UtilsTests COMMAND utilsTests.exe WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin/Debug)
set_property(TEST UtilsTests PROPERTY LABELS utils)