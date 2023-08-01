add_executable(GeometricAlgorithms main.cpp)

add_subdirectory(base)
add_subdirectory(geometry)
add_subdirectory(primitives)

target_link_libraries(GeometricAlgorithms
        PUBLIC
            base
            geometry
            primitives
)
