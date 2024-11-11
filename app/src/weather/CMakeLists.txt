cmake_minimum_required(VERSION 3.22)

set(SCRS
    ${CMAKE_CURRENT_LIST_DIR}/weather.c
)

add_library(weather INTERFACE)
target_sources(weather INTERFACE ${SCRS})
