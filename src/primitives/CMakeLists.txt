add_library(primitives "")

target_sources(primitives
        PRIVATE
        point.cpp
        line.cpp
        plane.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/point.h
        ${CMAKE_CURRENT_LIST_DIR}/line.h
        ${CMAKE_CURRENT_LIST_DIR}/plane.h
)

target_include_directories(primitives
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
