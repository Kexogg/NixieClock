#include "power.h"
#include <Arduino.h>

Powerline::Powerline(int channel, int frequency, int resolution, int pin, int duty) : Powerline(channel, frequency, resolution, pin)
{
    delay(2000);
    _duty = duty;
    ledcWrite(_channel, _duty);
};
Powerline::Powerline(int channel, int frequency, int resolution, int pin) : Powerline(channel, frequency, resolution)
{
    _pin = pin;
    pinMode(_pin, OUTPUT);
    ledcAttachPin(_pin, _channel);
};
Powerline::Powerline(int channel, int frequency, int resolution)
{
    _channel = channel;
    _frequency = frequency;
    _resolution = resolution;
    ledcSetup(_channel, _frequency, _resolution);
};
void Powerline::detach()
{
    ledcDetachPin(_pin);
};
void Powerline::attach()
{
    ledcAttachPin(_pin, _channel);
};
void Powerline::attach(int pin)
{
    _pin = pin;
    attach();
};
void Powerline::setFrequency(int frequency)
{
    _frequency = frequency;
    ledcChangeFrequency(_channel, _frequency, _resolution);
};
void Powerline::setResolution(int resolution)
{
    _resolution = resolution;
    ledcChangeFrequency(_channel, _frequency, _resolution);
};