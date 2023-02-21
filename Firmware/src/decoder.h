#pragma once
class Decoder
{
public:
	Decoder();
	Decoder(int pins[], byte *digitMask);
	int getCurrentDigit() { return currentDigit; };
	void setDigit(int digit);
	void writeData(byte data);
private:
	byte* _digitMask;
	int currentDigit = 0;
	int* _pins;
};
