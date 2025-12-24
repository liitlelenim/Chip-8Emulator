#include "RomFile.h"
#include <iostream>

RomFile::RomFile(const std::filesystem::path &romPath) {
    memoryContent.reserve(RomSizeInBytes);
    std::ifstream romInputFileStream = std::ifstream(romPath, std::ios::binary);
    ReadFile(romInputFileStream);
}

void RomFile::ReadFile(std::ifstream &romFile) {
    if (!romFile) {
        throw std::runtime_error("ROM file could not be opened");
    }

    int value;
    while ((value = romFile.get()) != EOF) {
        memoryContent.emplace_back(static_cast<std::byte>(value));
    }
}

const std::vector<std::byte> &RomFile::GetData() const {
    return memoryContent;
}

