# CMake의 최소 버전을 명시합니다.
cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LUA_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(LUA_INCLUDE "${LUA_PATH}/include")
set(LUA_SOURCE "${LUA_PATH}/src")

file(GLOB_RECURSE LUA_INCLUDE_FILE "${LUA_INCLUDE}/*")
file(GLOB_RECURSE LUA_SOURCE_FILE "${LUA_SOURCE}/*")

add_library(lua STATIC ${LUA_INCLUDE_FILE} ${LUA_SOURCE_FILE})

target_include_directories(lua PUBLIC ${LUA_INCLUDE})

source_group(include FILES ${LUA_INCLUDE_FILE})
source_group(src FILES ${LUA_SOURCE_FILE})