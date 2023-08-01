add_library(primitives "")

target_sources(primitives
        PRIVATE
        point.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/point.h
)

target_include_directories(primitives
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
