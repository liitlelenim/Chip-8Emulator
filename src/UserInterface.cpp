#include "UserInterface.h"
#include "imgui.h"
#include "EmulationSettings.h"

UserInterface::UserInterface(EmulationSettings &emulationSettings) : emulationSettings(emulationSettings) {

}

void UserInterface::Draw() {
    ImGui::SetNextWindowCollapsed(true, ImGuiCond_Once);
    ImGui::SetNextWindowPos({0, 0});
    ImGui::SetNextWindowSize(ImVec2(300, 150));
    ImGui::Begin("Settings", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoResize
    );

    ImGui::End();
}
