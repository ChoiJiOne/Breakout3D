cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(IMGUI_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(IMGUI_INCLUDE "${IMGUI_PATH}/include")
set(IMGUI_SOURCE "${IMGUI_PATH}/src")

file(GLOB_RECURSE IMGUI_INCLUDE_FILE "${IMGUI_INCLUDE}/*")
file(GLOB_RECURSE IMGUI_SOURCE_FILE "${IMGUI_SOURCE}/*")

add_library(imgui STATIC ${IMGUI_INCLUDE_FILE} ${IMGUI_SOURCE_FILE})

target_include_directories(imgui PUBLIC ${IMGUI_INCLUDE})
target_link_libraries(imgui SDL2)

source_group(include FILES ${IMGUI_INCLUDE_FILE})
source_group(src FILES ${IMGUI_SOURCE_FILE})