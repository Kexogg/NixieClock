#include <Arduino.h>
#include "decoder.h"

Decoder::Decoder(std::vector<int> pins, std::vector<int> digitMask)
{
    _pins = pins;
    for (int pin : _pins)
        pinMode(pin, OUTPUT);
    _digitMask = digitMask;
    setDigit(0);
}

void Decoder::setDigit(int digit)
{
    if (digit >= 0 and digit <= 9)
    {
        delay(1);
        if (digit != currentDigit)
        {
            currentDigit = digit;
            for (int i = 0; i < _pins.size(); i++)
                digitalWrite(_pins[i], bitRead(_digitMask[currentDigit], i));
        }
    }
}
