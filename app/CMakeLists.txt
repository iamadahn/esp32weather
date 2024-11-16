# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(esp32_weather)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_sources(app PRIVATE src/main.c)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/forecast)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/display)

target_link_libraries(app PRIVATE
    forecast
    display
)

include(${ZEPHYR_BASE}/samples/net/common/common.cmake)
