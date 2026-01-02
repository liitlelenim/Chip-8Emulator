#include <iostream>
#include <filesystem>
#include <thread>
#include "RomFile.h"
#include "Interpreter.h"
#include "DisplayWindow.h"
#include "EmulationSettings.h"
#include "UserInterface.h"

int main(int argc, char **argv) {


    EmulationSettings emulationSettings;
    UserInterface userInterface{emulationSettings};
    DisplayData displayData{emulationSettings};
    DisplayWindow window{displayData, userInterface};
    Interpreter interpreter{displayData};

    if (argc == 2) {

        std::filesystem::path romPath = argv[1];
        if (!std::filesystem::exists(romPath)) {
            std::cerr << "File not found: " << romPath;
        }
        RomFile romFile{romPath};
        interpreter.LoadRom(std::make_unique<const RomFile>(romFile));
    }

    while (window.ShouldBeOpen()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / emulationSettings.MaxInstructionsPerSecond));
        window.PollEvents();
        interpreter.PerformCurrentInstruction();
        window.Draw();
    }

    return EXIT_SUCCESS;
}
