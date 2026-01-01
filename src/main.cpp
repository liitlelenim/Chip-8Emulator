#include <iostream>
#include <filesystem>
#include <thread>
#include "RomFile.h"
#include "Interpreter.h"
#include "DisplayWindow.h"
#include "EmulationSettings.h"
#include "UserInterface.h"

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

    EmulationSettings emulationSettings;
    UserInterface userInterface{emulationSettings};
    RomFile romFile{romPath};
    DisplayData displayData{emulationSettings};
    DisplayWindow window{displayData, userInterface};
    Interpreter interpreter{romFile, displayData};

    while (window.ShouldBeOpen()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / emulationSettings.MaxInstructionsPerSecond));
        window.PollEvents();
        interpreter.PerformCurrentInstruction();
        window.Draw();
    }

    return EXIT_SUCCESS;
}
