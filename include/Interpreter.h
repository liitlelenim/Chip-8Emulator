#pragma once

#include <vector>
#include <memory>
#include <array>
#include "RomFile.h"

class Interpreter {
public:
    static constexpr size_t SizeOfMemoryInBytes = 0xFFF; //4096 bytes
    static constexpr size_t ProgramStartAddress = 0x200; //512 for most programs
public:
    explicit Interpreter(const RomFile &romFile);

private:
    std::vector<std::byte> memory{SizeOfMemoryInBytes};
    std::array<uint8_t, 16> Registers{0};
    uint16_t programCounter{ProgramStartAddress};
    uint8_t stackPointer{0};

};
