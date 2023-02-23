#pragma once
#include <time.h>
#include "sntp.h"
#include <vector>
#include <WiFi.h>

class Clock
{
public:
    const char *ntpServer1 = "pool.ntp.org";
    const char *ntpServer2 = "time.nist.gov";
    const long gmtOffset_sec = 3600;
    const int daylightOffset_sec = 0;
    const char *time_zone = "TZ_Asia_Yekaterinburg"; // TimeZone rule for Europe/Rome including daylight adjustment rules (optional)
    std::vector<int> returnTime();
    void setupTime();
private:
    int firstDigit(int n)
    {
        if (n < 10)
            return 0;
        return n / 10;
    }
    int lastDigit(int n)
    {
        return (n % 10);
    }
};