#pragma once


class EmulationSettings;
class Interpreter;

class UserInterface {

public:
    explicit UserInterface(EmulationSettings &emulationSettings, Interpreter& interpreter);
    void Draw();
private:
    EmulationSettings &emulationSettings;
    Interpreter &interpreter;
};
