#pragma once

#include <thread>

class Timers {
public:
    constexpr static long long RefreshTimeInMilliseconds = 1000 / 60;
    std::atomic<uint8_t> SoundTimer{};
    std::atomic<uint8_t> DelayTimer{};

    void ClearState();

private:
    std::thread timersThread;
    std::atomic<bool> isRunning{true};
public:
    Timers();
    ~Timers();

    void KillThread();

private:
    void CountDownOnTimers();
};
