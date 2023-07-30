add_executable(GeometricAlgorithms main.cpp)

add_subdirectory(base)

target_link_libraries(GeometricAlgorithms
        PRIVATE
            base
)
