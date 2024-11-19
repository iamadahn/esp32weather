cmake_minimum_required(VERSION 3.22)

set(SCRS
    ${CMAKE_CURRENT_LIST_DIR}/ths.c
)

add_library(ths INTERFACE)
target_sources(ths INTERFACE ${SCRS})
