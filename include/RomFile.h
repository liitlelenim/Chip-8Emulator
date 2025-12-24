#pragma once

#include <filesystem>
#include <vector>
#include <memory>
#include <fstream>

class RomFile {
public:
    static constexpr size_t RomSizeInBytes = 3584;
private:
    std::vector<std::byte> memoryContent;
public:
    explicit RomFile(const std::filesystem::path &romPath);

    [[nodiscard]] const std::vector<std::byte> &GetData() const;

private:
    void ReadFile(std::ifstream &romFile);

};
