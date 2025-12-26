#include <iostream>
#include "Interpreter.h"
#include "Input.h"

Interpreter::Interpreter(const RomFile &romFile) {
    const std::vector<std::byte> &romData = romFile.GetData();
    std::copy(romData.begin(), romData.end(), memory.begin() + ProgramStartAddress);
    InitializeMethodInstructions();
}

void Interpreter::PerformCurrentInstruction() {
    uint16_t fullOpCode = GetCurrentInstruction();
    instructionsMethods[static_cast<uint8_t>((fullOpCode & 0xF000) >> 12)](fullOpCode);
}

uint16_t Interpreter::GetCurrentInstruction() const {
    return static_cast<uint16_t>(memory[programCounter]) << 8
           | static_cast<uint16_t>(memory[programCounter + 1]);
}

void Interpreter::InitializeMethodInstructions() {
    instructionsMethods = {
            {0x0, [this](uint16_t opCode) { OP_0(opCode); }},
            {0x1, [this](uint16_t opCode) { OP_1(opCode); }},
            {0x2, [this](uint16_t opCode) { OP_2(opCode); }},
            {0x3, [this](uint16_t opCode) { OP_3(opCode); }},
            {0x4, [this](uint16_t opCode) { OP_4(opCode); }},
            {0x5, [this](uint16_t opCode) { OP_5(opCode); }},
            {0x6, [this](uint16_t opCode) { OP_6(opCode); }},
            {0x7, [this](uint16_t opCode) { OP_7(opCode); }},
            {0x8, [this](uint16_t opCode) { OP_8(opCode); }},
            {0x9, [this](uint16_t opCode) { OP_9(opCode); }},
            {0xA, [this](uint16_t opCode) { OP_A(opCode); }},
            {0xB, [this](uint16_t opCode) { OP_B(opCode); }},
            {0xC, [this](uint16_t opCode) { OP_C(opCode); }},
            {0xD, [this](uint16_t opCode) { OP_D(opCode); }},
            {0xE, [this](uint16_t opCode) { OP_E(opCode); }},
            {0xF, [this](uint16_t opCode) { OP_F(opCode); }},
    };

    OP_0SubInstructionsMethods = {
            {0xE0, [this](uint16_t opCode) { OP_0_0E0(opCode); }},
            {0xEE, [this](uint16_t opCode) { OP_0_0EE(opCode); }},
    };
    OP_8SubInstructionsMethods = {
            {0x0, [this](uint16_t opCode) { OP_8_xy0(opCode); }},
            {0x1, [this](uint16_t opCode) { OP_8_xy1(opCode); }},
            {0x2, [this](uint16_t opCode) { OP_8_xy2(opCode); }},
            {0x3, [this](uint16_t opCode) { OP_8_xy3(opCode); }},
            {0x4, [this](uint16_t opCode) { OP_8_xy4(opCode); }},
            {0x5, [this](uint16_t opCode) { OP_8_xy5(opCode); }},
            {0x6, [this](uint16_t opCode) { OP_8_xy6(opCode); }},
            {0x7, [this](uint16_t opCode) { OP_8_xy7(opCode); }},
            {0xE, [this](uint16_t opCode) { OP_8_xyE(opCode); }},
    };
    OP_ESubInstructionsMethods = {
            {0x9E, [this](uint16_t opCode) { OP_E_x9E(opCode); }},
            {0xA1, [this](uint16_t opCode) { OP_E_xA1(opCode); }},
    };
    OP_FSubInstructionsMethods = {
            {0x07, [this](uint16_t opCode) { OP_F_x07(opCode); }},
            {0x0A, [this](uint16_t opCode) { OP_F_x0A(opCode); }},
            {0x15, [this](uint16_t opCode) { OP_F_x15(opCode); }},
            {0x1E, [this](uint16_t opCode) { OP_F_x1E(opCode); }},
            {0x29, [this](uint16_t opCode) { OP_F_x29(opCode); }},
            {0x55, [this](uint16_t opCode) { OP_F_x55(opCode); }},
            {0x65, [this](uint16_t opCode) { OP_F_x65(opCode); }}
    };
}

void Interpreter::OP_0(uint16_t opCode) {
    OP_0SubInstructionsMethods[opCode & 0xFF](opCode);
}

void Interpreter::OP_1(uint16_t opCode) {
    uint16_t address = 0x0FFF & opCode;
    programCounter = address;
}

void Interpreter::OP_2(uint16_t opCode) {
    uint16_t address = 0x0FFF & opCode;
    stack[stackPointer++] = programCounter + InstructionSizeBytes;
    programCounter = address;
}

void Interpreter::OP_3(uint16_t opCode) {
    uint8_t registerIndex = (opCode & 0x0F00) >> 8;
    uint8_t valueToCompare = opCode & 0x00FF;

    if (registers[registerIndex] == valueToCompare) {
        programCounter += InstructionSizeBytes;
    }

    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_4(uint16_t opCode) {
    uint8_t registerIndex = (opCode & 0x0F00) >> 8;
    uint8_t valueToCompare = opCode & 0x00FF;

    if (registers[registerIndex] != valueToCompare) {
        programCounter += InstructionSizeBytes;
    }

    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_5(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;
    uint8_t yRegisterIndex = (opCode & 0x00F0) >> 4;

    if (registers[xRegisterIndex] == registers[yRegisterIndex]) {
        programCounter += InstructionSizeBytes;
    }

    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_6(uint16_t opCode) {
    uint8_t registerIndex = (opCode & 0x0F00) >> 8;
    uint8_t valueToSet = opCode & 0x00FF;
    registers[registerIndex] = valueToSet;
    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_7(uint16_t opCode) {
    uint8_t registerIndex = (opCode & 0x0F00) >> 8;
    uint8_t valueToSet = opCode & 0x00FF;
    registers[registerIndex] += valueToSet;
    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_8(uint16_t opCode) {
    OP_8SubInstructionsMethods[opCode & 0x000F](opCode);
}

void Interpreter::OP_9(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;
    uint8_t yRegisterIndex = (opCode & 0x00F0) >> 4;

    if (registers[xRegisterIndex] != registers[yRegisterIndex]) {
        programCounter += InstructionSizeBytes;
    }
    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_A(uint16_t opCode) {
    uint16_t address = opCode & 0x0FFF;
    IRegister = address;
    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_B(uint16_t opCode) {
    uint16_t address = opCode & 0x0FFF;
    programCounter = registers[0x0] + address;
}

void Interpreter::OP_C(uint16_t opCode) {
    uint8_t randomValue = randomNumberGenerator.GetRandomValue();
    uint8_t xRegisterIndex = (0x0F00 & opCode) >> 8;
    registers[xRegisterIndex] = randomValue & (opCode & 0xFF);
    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_D(uint16_t opCode) {

}

void Interpreter::OP_E(uint16_t opCode) {
    OP_ESubInstructionsMethods[opCode & 0xFF](opCode);
}

void Interpreter::OP_F(uint16_t opCode) {

}

void Interpreter::OP_0_0E0(uint16_t opCode) {

}

void Interpreter::OP_0_0EE(uint16_t opCode) {
    programCounter = stack[--stackPointer];
}

void Interpreter::OP_8_xy0(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;
    uint8_t yRegisterIndex = (opCode & 0x00F0) >> 4;
    registers[xRegisterIndex] = registers[yRegisterIndex];
    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_8_xy1(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;
    uint8_t yRegisterIndex = (opCode & 0x00F0) >> 4;
    registers[xRegisterIndex] = registers[xRegisterIndex] | registers[yRegisterIndex];
    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_8_xy2(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;
    uint8_t yRegisterIndex = (opCode & 0x00F0) >> 4;
    registers[xRegisterIndex] = registers[xRegisterIndex] & registers[yRegisterIndex];
    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_8_xy3(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;
    uint8_t yRegisterIndex = (opCode & 0x00F0) >> 4;
    registers[xRegisterIndex] = registers[xRegisterIndex] ^ registers[yRegisterIndex];
    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_8_xy4(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;
    uint8_t yRegisterIndex = (opCode & 0x00F0) >> 4;

    uint16_t sum = registers[xRegisterIndex] + registers[yRegisterIndex];
    registers[0xF] = sum > 0xFF ? 1 : 0;
    registers[xRegisterIndex] = static_cast<uint8_t>(sum & 0xFF);
    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_8_xy5(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;
    uint8_t yRegisterIndex = (opCode & 0x00F0) >> 4;

    registers[0xF] = registers[xRegisterIndex] > registers[yRegisterIndex] ? 1 : 0;
    registers[xRegisterIndex] -= registers[yRegisterIndex];

    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_8_xy6(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;;
    registers[0xF] = registers[xRegisterIndex] & 1;
    registers[xRegisterIndex] >>= 1;

    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_8_xy7(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;
    uint8_t yRegisterIndex = (opCode & 0x00F0) >> 4;

    registers[0xF] = registers[yRegisterIndex] > registers[xRegisterIndex] ? 1 : 0;
    registers[xRegisterIndex] = registers[yRegisterIndex] - registers[xRegisterIndex];

    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_8_xyE(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;
    registers[0xF] = (registers[xRegisterIndex] >> 7) & 1;
    registers[xRegisterIndex] <<= 1;

    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_E_x9E(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;
    sf::Keyboard::Key checkedKey = Input::ValueToKey[registers[xRegisterIndex]];
    if (sf::Keyboard::isKeyPressed(checkedKey)) {
        programCounter += InstructionSizeBytes;
    }
    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_E_xA1(uint16_t opCode) {
    uint8_t xRegisterIndex = (opCode & 0x0F00) >> 8;
    sf::Keyboard::Key checkedKey = Input::ValueToKey[registers[xRegisterIndex]];
    if (!sf::Keyboard::isKeyPressed(checkedKey)) {
        programCounter += InstructionSizeBytes;
    }
    programCounter += InstructionSizeBytes;
}

void Interpreter::OP_F_x07(uint16_t opCode) {

}

void Interpreter::OP_F_x0A(uint16_t opCode) {

}

void Interpreter::OP_F_x15(uint16_t opCode) {

}

void Interpreter::OP_F_x18(uint16_t opCode) {

}

void Interpreter::OP_F_x1E(uint16_t opCode) {

}

void Interpreter::OP_F_x29(uint16_t opCode) {

}

void Interpreter::OP_F_x33(uint16_t opCode) {

}

void Interpreter::OP_F_x55(uint16_t opCode) {

}

void Interpreter::OP_F_x65(uint16_t opCode) {

}

