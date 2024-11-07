cmake_minimum_required(VERSION 3.22)

set(SCRS
    ${CMAKE_CURRENT_LIST_DIR}/wifi.c
)

add_library(wifi INTERFACE)
target_sources(wifi INTERFACE ${SCRS})
