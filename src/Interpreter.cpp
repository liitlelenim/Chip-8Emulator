#include <iostream>
#include "Interpreter.h"

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
}

void Interpreter::OP_0(uint16_t opCode) {
}

void Interpreter::OP_1(uint16_t opCode) {

}

void Interpreter::OP_2(uint16_t opCode) {

}

void Interpreter::OP_3(uint16_t opCode) {

}

void Interpreter::OP_4(uint16_t opCode) {

}

void Interpreter::OP_5(uint16_t opCode) {

}

void Interpreter::OP_6(uint16_t opCode) {

}

void Interpreter::OP_7(uint16_t opCode) {

}

void Interpreter::OP_8(uint16_t opCode) {

}

void Interpreter::OP_9(uint16_t opCode) {

}

void Interpreter::OP_A(uint16_t opCode) {

}

void Interpreter::OP_B(uint16_t opCode) {

}

void Interpreter::OP_C(uint16_t opCode) {

}

void Interpreter::OP_D(uint16_t opCode) {

}

void Interpreter::OP_E(uint16_t opCode) {

}

void Interpreter::OP_F(uint16_t opCode) {

}
