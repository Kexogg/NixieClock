#pragma once
#include <vector>
class Decoder
{
public:
	Decoder();
	Decoder(std::vector<int> pins, std::vector<int> digitMask);
	int getCurrentDigit() { return currentDigit; };
	void setDigit(int digit);

private:
	std::vector<int> _digitMask;
	std::vector<int> _pins;
	int currentDigit = 0;
};
