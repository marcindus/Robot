cmake_minimum_required(VERSION 3.5)
project(robot_test)

set(CMAKE_CXX_STANDARD 14)
#add_compile_options(-Wall -Wextra -pedantic -Werror)
add_compile_options(-Wall  -Werror)

include(cmake/GTest.cmake)

include_directories(
        ${GTEST_INCLUDE_DIRS}
        ${GMOCK_INCLUDE_DIRS}
        src
        test
)
file(GLOB TEST_SOURCES
    "unittest.cpp"
    "test/*.cpp"
    "src/GpioPort.cpp"
    "src/GpioException.cpp"

    )

add_executable(tests ${SOURCES} ${TEST_SOURCES})
target_link_libraries(tests
        gtest
        gmock
        gtest_main)

set_property(TARGET tests PROPERTY CXX_STANDARD 14)

#this is a bit of overkill, but it enables to run ctest
enable_testing()

add_test(
        NAME allTests
        COMMAND tests
)
