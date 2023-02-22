#pragma once

class Lamp
{
public:
    Lamp();
    Lamp(int pin);
    void toggle();
    void setState(bool state);
    bool isOn() { return _state; }

private:
    int _pin;
    bool _state = false;
};
