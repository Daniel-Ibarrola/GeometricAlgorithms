add_library(base "")

target_sources(base
        PRIVATE
            core.cpp
            vec.cpp
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/core.h
            ${CMAKE_CURRENT_LIST_DIR}/vec.h
)

target_include_directories(base
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
