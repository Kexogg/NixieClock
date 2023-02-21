#include <Arduino.h>
#include "decoder.h"

Decoder::Decoder(int *pins, byte *digitMask)
{
    _pins = pins;
    for (size_t i = 0; i < sizeof(_pins) / sizeof(*_pins); i++)
        pinMode(_pins[i], OUTPUT);
    _digitMask = digitMask;
}

void Decoder::setDigit(int digit)
{
    if (digit >= 0 and digit <= 9)
        writeData(byte(digit));
}
void Decoder::writeData(byte data)
{
    currentDigit = _digitMask[data];
    for (size_t i = 0; i < sizeof(_pins) / sizeof(*_pins); i++)
        digitalWrite(_pins[i], bitRead(currentDigit, i));
    delay(1);
}
