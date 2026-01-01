#pragma once


class EmulationSettings;

class UserInterface {

public:
    explicit UserInterface(EmulationSettings &emulationSettings);
    void Draw();
private:
    EmulationSettings &emulationSettings;
};
