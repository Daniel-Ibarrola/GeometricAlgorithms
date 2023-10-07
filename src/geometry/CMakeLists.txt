add_library(geometry "")

target_sources(geometry
        PRIVATE
        geoutils.cpp
        intersection.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/geoutils.h
        ${CMAKE_CURRENT_LIST_DIR}/intersection.h
)

target_include_directories(geometry
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
