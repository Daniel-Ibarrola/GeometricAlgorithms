project(Google_tests)
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(
        Google_Tests_run
        base/test_core.cpp
        base/test_vector.cpp
)

target_link_libraries(Google_Tests_run base)
target_link_libraries(Google_Tests_run gtest gtest_main)
