cmake_minimum_required(VERSION 3.22)

set(SCRS
    ${CMAKE_CURRENT_LIST_DIR}/images/wife.c
    ${CMAKE_CURRENT_LIST_DIR}/widgets.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/jetbrains_12.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/jetbrains_14.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/jetbrains_18.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/jetbrains_20.c
    ${CMAKE_CURRENT_LIST_DIR}/fonts/jetbrains_28.c
)

add_library(widgets INTERFACE)
target_sources(widgets INTERFACE ${SCRS})
