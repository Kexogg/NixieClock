#include "lamp.h"
#include <Arduino.h>

Lamp::Lamp(){};

Lamp::Lamp(int pin)
{
    _pin = pin;
    pinMode(_pin, OUTPUT);
}
void Lamp::toggle()
{
    setState(!_state);
};
void Lamp::setState(bool state)
{
    _state = state;
    digitalWrite(_pin, _state);
}
