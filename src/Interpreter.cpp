#include "Interpreter.h"

Interpreter::Interpreter(const RomFile &romFile) {
    const std::vector<std::byte> &romData = romFile.GetData();
    std::copy(romData.begin(), romData.end(), memory.begin() + ProgramStartAddress);
}
