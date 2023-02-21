#include <Arduino.h>
#include "config.h"
/*#include "lamp.h"
#include "power.h"*/
#include "display.h"

Display display(config.lampPins, config.decoderPins, config.generator, 0, config.frequency, config.duty);

void setup()
{
  int data[4] = {0, 0, 0, 0};
  display.setData(data);
}

void loop()
{
  display.cycle();
  /*int data[4] = {sussy / 1000 % 10, sussy / 100 % 10, sussy / 10 % 10, sussy % 10}; // TODO
  for (int i = 0; i < sizeof(lamps)/sizeof(*lamps); i++)
  {
    lamps[i].setDigit(data[i]);
    delay(1);
    lamps[i].toggle(1);
  };
  sussy += 1;*/
};
