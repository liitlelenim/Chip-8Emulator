cmake_minimum_required(VERSION 3.16)
project(CHIP8Emulator)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin CACHE PATH "Output directory" FORCE)

set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/SFML-3.0.2/)

add_subdirectory(vendor/imgui-1.91.9)
target_link_libraries(imgui
        PUBLIC
        SFML::System
        SFML::Window
        SFML::Graphics
)

add_executable(CHIP8Emulator
        src/main.cpp
        src/RomFile.cpp
        include/RomFile.h
        src/Interpreter.cpp
        include/Interpreter.h
        src/DisplayWindow.cpp
        include/DisplayWindow.h
        include/Input.h
        src/RandomNumberGenerator.cpp
        include/RandomNumberGenerator.h
        src/DisplayData.cpp
        include/DisplayData.h
        include/HexadecimalSprites.h
        src/Timers.cpp
        include/Timers.h
)

target_link_libraries(CHIP8Emulator
        SFML::System
        SFML::Window
        SFML::Graphics
        imgui)

target_include_directories(CHIP8Emulator PUBLIC
        include
        vendor/SFML-3.0.2/include
)

set_target_properties(CHIP8Emulator PROPERTIES
        OUTPUT_NAME "CHIP8Emulator"
)
