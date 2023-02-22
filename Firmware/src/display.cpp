#include "display.h"
#include <vector>
#include <Arduino.h>
Display::Display(std::vector<int> lampPins, std::vector<int> decoderPins, std::vector<int> digitMask, int powerlinePin, int channel, int frequency, int duty)
{
    _powerline = new Powerline(channel, frequency, 8, powerlinePin, duty);
    _decoder = new Decoder(decoderPins, digitMask);
    for (int i = 0; i < lampPins.size(); i++)
        _lamps.push_back(Lamp(lampPins[i]));
}

void Display::cycle()
{
    for (int i = 0; i < _data.size(); i++)
    {
        _decoder->setDigit(_data[i]);
        _lamps[i].toggle();
        delay(1);
        _lamps[i].toggle();
    };
}

void Display::setData(std::vector<int> data)
{
    _data = data;
}
