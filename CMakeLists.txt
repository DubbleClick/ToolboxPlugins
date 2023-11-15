cmake_minimum_required(VERSION 3.16)

set(CMAKE_GENERATOR_PLATFORM win32)

project(tb_plugin)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(NOT(CMAKE_SIZEOF_VOID_P EQUAL 4))
    message(FATAL_ERROR "You are configuring a non 32-bit build, this is not supported. Run cmake with `-A Win32`")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/")

add_compile_options(/MP /permissive-)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(gwtoolboxpp)

add_library(tb_plugin SHARED)

file(GLOB SOURCES
    "*.h"
    "*.cpp"
	${gwtoolboxpp_SOURCE_DIR}/plugins/Base/*.h
	${gwtoolboxpp_SOURCE_DIR}/plugins/Base/*.ixx
	${gwtoolboxpp_SOURCE_DIR}/plugins/Base/*.cpp
    )

target_include_directories(tb_plugin PRIVATE
	${gwtoolboxpp_SOURCE_DIR}/plugins/Base
	${gwtoolboxpp_SOURCE_DIR}/GWToolboxdll
	)
target_link_libraries(tb_plugin PRIVATE
    RestClient
    imgui
    directxtex
    gwca
    earcut
    easywsclient
    discord_game_sdk
    nlohmann_json::nlohmann_json
    simpleini
    imgui::fonts
    IconFontCppHeaders
    nativefiledialog
    wintoast
    )
target_link_options(tb_plugin PRIVATE
    "$<$<CONFIG:DEBUG>:/NODEFAULTLIB:LIBCMT>"
    )
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})
target_sources(tb_plugin PRIVATE ${SOURCES})
target_compile_definitions(tb_plugin PRIVATE
    "NOMINMAX"
    "_WIN32_WINNT=_WIN32_WINNT_WIN7"
    "WIN32_LEAN_AND_MEAN"
    "VC_EXTRALEAN"
    )
