cmake_minimum_required(VERSION 3.27)

project(ProjectB)

set(PROJECT_NAME "Breakout3D")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(ThirdParty/SDL)
add_subdirectory(ThirdParty/cgltf)
add_subdirectory(ThirdParty/glad)
add_subdirectory(ThirdParty/imgui)
add_subdirectory(ThirdParty/jsoncpp)
add_subdirectory(ThirdParty/lua)
add_subdirectory(ThirdParty/miniaudio)
add_subdirectory(ThirdParty/stb)

set_target_properties(
    cgltf
    glad
    imgui
    jsoncpp
    lua
    miniaudio
    SDL2 
    SDL2main 
    sdl_headers_copy
    stb 
    PROPERTIES FOLDER "ThirdParty"
)

set(PROJECT_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/Inc")
set(PROJECT_SOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/Src")
set(SCRIPT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Script")
set(SHADER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Shader")

file(GLOB_RECURSE PROJECT_INCLUDE_FILE "${PROJECT_INCLUDE_PATH}/**")
file(GLOB_RECURSE PROJECT_SOURCE_FILE "${PROJECT_SOURCE_PATH}/**")
file(GLOB_RECURSE SCRIPT_SOURCE_FILE "${SCRIPT_PATH}/*")
file(GLOB_RECURSE SHADER_SOURCE_FILE "${SHADER_PATH}/*")

add_executable(
    ${PROJECT_NAME} 
    WIN32 
    ${PROJECT_INCLUDE_FILE}
    ${PROJECT_SOURCE_FILE} 
    ${SCRIPT_SOURCE_FILE} 
    ${SHADER_SOURCE_FILE}
)

target_include_directories(
    ${PROJECT_NAME} 
    PUBLIC 
    ${PROJECT_INCLUDE_PATH} 
    ${PROJECT_SOURCE_PATH}
)

target_link_libraries(
    ${PROJECT_NAME} 
    PUBLIC 
    Dbghelp.lib 
    Pathcch.lib 
    Shlwapi.lib
    cgltf
    glad
    imgui
    jsoncpp
    lua
    miniaudio
    SDL2
    stb 
)

target_compile_definitions(
    ${PROJECT_NAME} 
    PUBLIC
    $<$<CONFIG:Debug>:DEBUG_MODE>
    $<$<CONFIG:Release>:RELEASE_MODE>
    $<$<CONFIG:RelWithDebInfo>:DEVELOPMENT_MODE>
    $<$<CONFIG:MinSizeRel>:SHIPPING_MODE>
)

set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

source_group(TREE "${PROJECT_INCLUDE_PATH}" PREFIX "${PROJECT_NAME}/Inc" FILES ${PROJECT_INCLUDE_FILE})
source_group(TREE "${PROJECT_SOURCE_PATH}" PREFIX "${PROJECT_NAME}/Src" FILES ${PROJECT_SOURCE_FILE})
source_group(Script FILES ${SCRIPT_SOURCE_FILE})
source_group(Shader FILES ${SHADER_SOURCE_FILE})