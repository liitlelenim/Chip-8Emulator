#include <iostream>
#include <filesystem>
#include "RomFile.h"
#include "Interpreter.h"
#include "DisplayWindow.h"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Proper usage:\n" << argv[0] << " [rom-path]";
        return EXIT_FAILURE;
    }

    std::filesystem::path romPath = argv[1];
    if (!std::filesystem::exists(romPath)) {
        std::cerr << "File not found: " << romPath;
        return EXIT_FAILURE;
    }

    RomFile romFile{romPath};
    DisplayData displayData{};
    DisplayWindow window{displayData};
    Interpreter interpreter{romFile,displayData};

    while (window.ShouldBeOpen()) {
        window.PollEvents();
        interpreter.PerformCurrentInstruction();
        window.Draw();
    }

    return EXIT_SUCCESS;
}
