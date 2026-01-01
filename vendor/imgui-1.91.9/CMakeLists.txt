project(imgui)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)


add_library(imgui STATIC
        imgui_demo.cpp
        imgui_tables.cpp
        imgui_widgets.cpp
        imconfig.h
        imgui.h
        imgui.cpp
        imgui_internal.h
        imstb_rectpack.h
        imstb_textedit.h
        imstb_truetype.h
        imgui-SFML.cpp
        imgui-SFML.h
        imgui-SFML_export.h
        imgui_draw.cpp
)
target_include_directories(imgui PUBLIC .)