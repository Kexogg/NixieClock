#pragma once
#include <vector>
#include "power.h"
#include "lamp.h"
#include "decoder.h"

class Display
{
public:
    Display(std::vector<int> lampPins, std::vector<int> decoderPins, std::vector<int> digitMask, int powerlinePin, int channel, int frequency, int duty);
    void cycle();
    void setData(std::vector<int> data);
    void setBrightness(int brightness);
    std::vector<Lamp> _lamps;

private:
    std::vector<int> _data;
    Powerline *_powerline;
    Decoder *_decoder;
};
