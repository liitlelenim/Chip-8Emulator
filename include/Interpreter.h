#pragma once

#include <vector>
#include <memory>
#include <array>
#include <unordered_map>
#include <functional>
#include "RomFile.h"

class Interpreter {
public:
    static constexpr size_t SizeOfMemoryInBytes = 0xFFF; //4096 bytes
    static constexpr size_t ProgramStartAddress = 0x200; //512 for most programs
private:
    std::vector<std::byte> memory{SizeOfMemoryInBytes};

    std::array<uint8_t, 16> Registers{0};
    uint16_t programCounter{ProgramStartAddress};
    uint8_t stackPointer{0};

    std::unordered_map<uint8_t, std::function<void(uint16_t opCode)>> instructionsMethods;

public:
    explicit Interpreter(const RomFile &romFile);

    void PerformCurrentInstruction();

private:
    [[nodiscard]] uint16_t GetCurrentInstruction() const;

    void InitializeMethodInstructions();

    void OP_0(uint16_t opCode);

    void OP_1(uint16_t opCode);

    void OP_2(uint16_t opCode);

    void OP_3(uint16_t opCode);

    void OP_4(uint16_t opCode);

    void OP_5(uint16_t opCode);

    void OP_6(uint16_t opCode);

    void OP_7(uint16_t opCode);

    void OP_8(uint16_t opCode);

    void OP_9(uint16_t opCode);

    void OP_A(uint16_t opCode);

    void OP_B(uint16_t opCode);

    void OP_C(uint16_t opCode);

    void OP_D(uint16_t opCode);

    void OP_E(uint16_t opCode);

    void OP_F(uint16_t opCode);

};
