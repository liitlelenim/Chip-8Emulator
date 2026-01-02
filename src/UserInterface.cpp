#include "UserInterface.h"
#include "imgui.h"
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
    ImGui::End();
}
