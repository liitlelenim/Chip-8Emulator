cmake_minimum_required(VERSION 3.30)
project(CHIP_8Emulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(CHIP_8Emulator
        src/main.cpp
        src/RomFile.cpp
        include/RomFile.h)

target_include_directories(CHIP_8Emulator PRIVATE
        include)
