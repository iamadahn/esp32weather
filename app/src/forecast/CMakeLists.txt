cmake_minimum_required(VERSION 3.22)

set(SCRS
    ${CMAKE_CURRENT_LIST_DIR}/forecast.c
    ${CMAKE_CURRENT_LIST_DIR}/wifi.c
)

add_library(forecast INTERFACE)
target_sources(forecast INTERFACE ${SCRS})
