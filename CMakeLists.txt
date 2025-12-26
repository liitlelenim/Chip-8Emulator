cmake_minimum_required(VERSION 3.30)
project(CHIP_8Emulator)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(vendor/SFML-3.0.2/)

add_executable(CHIP_8Emulator
        src/main.cpp
        src/RomFile.cpp
        include/RomFile.h
        src/Interpreter.cpp
        include/Interpreter.h
        src/DisplayWindow.cpp
        include/DisplayWindow.h
        include/Input.h
)

target_link_libraries(CHIP_8Emulator
        SFML::System
        SFML::Window
        SFML::Main
        SFML::Graphics)
target_include_directories(CHIP_8Emulator PRIVATE
        include
        vendor/SFML-3.0.2/include)
