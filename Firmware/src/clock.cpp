#include "clock.h"

std::vector<int> Clock::returnTime()
{
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        return {8, 8, 8, 8};
    }
    return {firstDigit(timeinfo.tm_min), lastDigit(timeinfo.tm_min), firstDigit(timeinfo.tm_sec), lastDigit(timeinfo.tm_sec)};
}

void Clock::setupTime()
{
    /**
     * NTP server address could be aquired via DHCP,
     *
     * NOTE: This call should be made BEFORE esp32 aquires IP address via DHCP,
     * otherwise SNTP option 42 would be rejected by default.
     * NOTE: configTime() function call if made AFTER DHCP-client run
     * will OVERRIDE aquired NTP server address
     */
    sntp_servermode_dhcp(1); // (optional)
    configTzTime(time_zone, ntpServer1, ntpServer2);
}