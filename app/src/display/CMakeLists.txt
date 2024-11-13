cmake_minimum_required(VERSION 3.22)

set(SCRS
    ${CMAKE_CURRENT_LIST_DIR}/display.c
)

add_library(display INTERFACE)
target_sources(display INTERFACE ${SCRS})
