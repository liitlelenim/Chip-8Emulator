#include "UserInterface.h"
#include <imgui.h>
#include <ImGuiFileDialog.h>
#include "EmulationSettings.h"
#include "Interpreter.h"

UserInterface::UserInterface(EmulationSettings &emulationSettings, Interpreter &interpreter) : emulationSettings(
        emulationSettings), interpreter(interpreter) {

}

void UserInterface::Draw() {
    ImGui::SetNextWindowCollapsed(true, ImGuiCond_Once);
    ImGui::SetNextWindowPos({0, 0});
    ImGui::SetNextWindowSize(ImVec2(800, 150));
    ImGui::Begin("Settings", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoResize
    );

    ImGui::SliderInt("Max instruction amount per seconds", &emulationSettings.MaxInstructionsPerSecond, 10, 1000);
    ImGui::ColorEdit4("Pixel color", emulationSettings.PixelColor);
    ImGui::ColorEdit4("Background color", emulationSettings.BackgroundColor);
    if (ImGui::Button("Restart")) {
        interpreter.ClearState();
    }

    if (ImGui::Button("Load ROM")) {
        ImGuiFileDialog::Instance()->OpenDialog(
                "ChooseFileDlgKey",
                "Choose a file",
                ".rom,.ch8,.chip8");
    }

    if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey")) {
        if (ImGuiFileDialog::Instance()->IsOk()) {
            std::string filePath =
                    ImGuiFileDialog::Instance()->GetFilePathName();

            std::filesystem::path romPath = filePath;

            if (std::filesystem::exists(romPath)) {
                interpreter.UpdateRomFile(std::make_unique<const RomFile>(romPath));
            }
        }
        ImGuiFileDialog::Instance()->Close();
    }
    ImGui::End();
}
