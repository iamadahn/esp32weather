# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

set(EXTRA_COMPONENT_DIRS 
    drivers/epaper
    modules/display_controller
    )

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp32weather)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

