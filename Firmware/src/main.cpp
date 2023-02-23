#include <Arduino.h>
#include <WiFi.h>
#include "config.h"
#include "display.h"
#include "clock.h"
Display *display;
Clock *_time;
int lastupdate = 0;
void notify()
{
    digitalWrite(15, 1);
    delay(5);
    digitalWrite(15, 0);
}

void setup()
{
    display = new Display(config.lampPins, config.decoderPins, config.digitMask, config.generator, 1, config.frequency, config.duty);
    _time = new Clock();
    pinMode(15, OUTPUT);
    notify();
    _time->setupTime();
    WiFi.begin(config.ssid, config.password);
    while (WiFi.status() != WL_CONNECTED)
    {
        notify();
        delay(500);
    }
    delay(5000);
    WiFi.disconnect();
}

void loop()
{
    display->setData(_time->returnTime());
    while (true)
    {
        long currentTime = millis();
        if (currentTime - lastupdate > 1000)
        {
            lastupdate = currentTime;
            display->setData(_time->returnTime());
        }
        display->cycle();
    }
}