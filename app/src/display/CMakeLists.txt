cmake_minimum_required(VERSION 3.22)

set(SCRS
    ${CMAKE_CURRENT_LIST_DIR}/images/wife.c
    ${CMAKE_CURRENT_LIST_DIR}/display.c
    ${CMAKE_CURRENT_LIST_DIR}/widgets.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/jetbrains_12.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/jetbrains_14.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/jetbrains_18.c
)

add_library(display INTERFACE)
target_sources(display INTERFACE ${SCRS})
