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
    std::array<uint16_t, 16> stack{};
    std::unordered_map<uint8_t, std::function<void(uint16_t opCode)>> instructionsMethods;
    std::unordered_map<uint8_t, std::function<void(uint16_t opCode)>> OP_0SubInstructionsMethods;
    std::unordered_map<uint8_t, std::function<void(uint16_t opCode)>> OP_8SubInstructionsMethods;
    std::unordered_map<uint8_t, std::function<void(uint16_t opCode)>> OP_ESubInstructionsMethods;
    std::unordered_map<uint8_t, std::function<void(uint16_t opCode)>> OP_FSubInstructionsMethods;

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

    void OP_0_0EE(uint16_t opCode);

    void OP_0_0E0(uint16_t opCode);

    void OP_8_xy0(uint16_t opCode);

    void OP_8_xy1(uint16_t opCode);

    void OP_8_xy2(uint16_t opCode);

    void OP_8_xy3(uint16_t opCode);

    void OP_8_xy4(uint16_t opCode);

    void OP_8_xy5(uint16_t opCode);

    void OP_8_xy6(uint16_t opCode);

    void OP_8_xy7(uint16_t opCode);

    void OP_8_xyE(uint16_t opCode);

    void OP_E_x9E(uint16_t opCode);

    void OP_E_xA1(uint16_t opCode);

    void OP_F_x07(uint16_t opCode);

    void OP_F_x0A(uint16_t opCode);

    void OP_F_x15(uint16_t opCode);

    void OP_F_x18(uint16_t opCode);

    void OP_F_x1E(uint16_t opCode);

    void OP_F_x29(uint16_t opCode);

    void OP_F_x33(uint16_t opCode);

    void OP_F_x55(uint16_t opCode);

    void OP_F_x65(uint16_t opCode);
};
