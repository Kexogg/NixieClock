#include "display.h"
#include <vector>

Display::Display(int lampPins[], int decoderPins[], int powerlinePin, int channel, int frequency, int duty)
{
    int lampsCount = sizeof(lampPins) / sizeof(*lampPins);
    for (int i = 0; i < lampsCount; i++)
    {
        _lamps.push_back(Lamp(lampPins[i]));
    }
    _powerline = Powerline(channel, frequency, 8, powerlinePin, duty);
}

void Display::cycle()
{
    for (int i = 0; i < _data.size(); i++)
    {
        _decoder.setDigit(_data[i]);
        _lamps[i].toggle();
        delay(1);
        _lamps[i].toggle();
    };
}

void Display::setData(int data[])
{
}
