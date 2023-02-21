#pragma once
#include <vector>
#include "power.h"
#include "lamp.h"
#include "decoder.h"

class Display {
public:
    //Display(Lamp *lamps, Decoder *decoder, Powerline *powerline);
    Display(int lampPins[], int decoderPins[], int PowerlinePin, int channel, int frequency, int duty);
    
    void cycle();
    void setData(int data[]);
    void setBrightness(int brightness);
private:

    std::vector<Lamp> _lamps;
    std::vector<int> _data;
    Powerline _powerline;
    Decoder _decoder;
};
