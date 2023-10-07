project(Google_tests)
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(
        Google_Tests_run
        base/test_core.cpp
        base/test_vector.cpp
        primitives/test_point.cpp
        primitives/test_plane.cpp
        geometry/test_geo_utils.cpp
        geometry/test_intersection.cpp
)

target_link_libraries(Google_Tests_run base)
target_link_libraries(Google_Tests_run geometry)
target_link_libraries(Google_Tests_run primitives)
target_link_libraries(Google_Tests_run gtest gtest_main)
