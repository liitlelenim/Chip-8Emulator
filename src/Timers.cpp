#include <chrono>
#include <mutex>
#include "Timers.h"

Timers::Timers() {
    timersThread = std::thread([this]() { CountDownOnTimers(); });
};

void Timers::CountDownOnTimers() {
    while (isRunning) {
        std::this_thread::sleep_for(std::chrono::milliseconds(RefreshTimeInMilliseconds));

        if (SoundTimer > 0) SoundTimer--;
        if (DelayTimer > 0) DelayTimer--;
    }
}

void Timers::ClearState() {
    SoundTimer = 0;
    DelayTimer = 0;
}

void Timers::KillThread() {
    isRunning = false;
}

Timers::~Timers() {
    KillThread();
    if (timersThread.joinable()) {
        timersThread.join();
    }
}
