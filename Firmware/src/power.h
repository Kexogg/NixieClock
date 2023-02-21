#pragma once
#include <Arduino.h>
class Powerline
{
public:
    Powerline(){};
    Powerline(int channel, int frequency, int resolution, int pin, int duty)
    {
        Powerline(channel, frequency, resolution, pin);
        _duty = duty;
        ledcWrite(_channel, _duty);
    };
    Powerline(int channel, int frequency, int resolution, int pin)
    {
        Powerline(channel, frequency, resolution);
        _pin = pin;
        pinMode(_pin, OUTPUT);
        ledcAttachPin(_pin, _channel);
    }
    Powerline(int channel, int frequency, int resolution)
    {
        _channel = channel;
        _frequency = frequency;
        _resolution = resolution;
        ledcSetup(_channel, _frequency, _resolution);   
    };
    void detach()
    {
        ledcDetachPin(_pin);
    };
    void attach()
    {
        ledcAttachPin(_pin, _channel);
    };
    void attach(int pin)
    {
        _pin = pin;
        attach();
    };
    void setFrequency(int frequency)
    {
        _frequency = frequency;
        ledcChangeFrequency(_channel, _frequency, _resolution);
    };
    void setResolution(int resolution)
    {
        _resolution = resolution;
        ledcChangeFrequency(_channel, _frequency, _resolution);
    };

private:
    int _pin;
    int _frequency;
    int _resolution;
    int _channel;
    int _duty;
};