#pragma once
// #include <Arduino.h>
class Powerline
{
public:
    Powerline(int channel, int frequency, int resolution, int pin, int duty);
    Powerline(int channel, int frequency, int resolution, int pin);
    Powerline(int channel, int frequency, int resolution);

    void detach();
    void attach();
    void attach(int pin);
    void setFrequency(int frequency);
    void setResolution(int resolution);

private:
    int _pin;
    int _frequency;
    int _resolution;
    int _channel;
    int _duty;
};