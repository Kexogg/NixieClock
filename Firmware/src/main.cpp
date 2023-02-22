#include <Arduino.h>
#include "config.h"
#include "display.h"

Display *display;

void setup()
{
  display = new Display(config.lampPins, config.decoderPins, config.digitMask, config.generator, 1, config.frequency, config.duty);
  pinMode(15, OUTPUT);
  digitalWrite(15, 1);
  std::vector<int> data = {1, 1, 1, 1};
  display->setData(data);
}

void loop()
{
  display->cycle();
}
