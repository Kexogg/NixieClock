#pragma once
#include <vector>
class Config
{
public:
    int delay = 1;
    int frequency = 30000;
    int duty = 150;
    int resolution = 8;
    int generator = 9;

    std::vector<int> decoderPins = {35, 18, 16, 33}; // 3 1 4 2
    std::vector<int> lampPins = {7, 5, 3, 1};
    std::vector<int> backlight = {11, 12, 14};
    std::vector<int> freeGPIO = {36, 38, 40};
    std::vector<int> digitMask = {9, 8, 0, 5, 4, 7, 3, 6, 2, 1}; // маска дешифратора платы in14
    int dot = 13;
};
extern Config config;