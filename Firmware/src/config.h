#pragma once
#include <Arduino.h>
class Config
{
public:
    int delay = 1;
    int frequency = 25000;
    int duty = 180;
    int resolution = 8;

    //int decoder[4] = {16, 18, 33, 35};
    int decoderPins[4] = {35, 18, 16, 33}; // 3 1 4 2

    int lampPins[4] = {7, 5, 3, 1};
    int backlight[3] = {11, 12, 14};
    int freeGPIO[3] = {36, 38, 40};
    int generator = 9;
    int dot = 13;
    byte digitMask[10] = {9, 8, 0, 5, 4, 7, 3, 6, 2, 1}; // маска дешифратора платы in14
};
extern Config config;