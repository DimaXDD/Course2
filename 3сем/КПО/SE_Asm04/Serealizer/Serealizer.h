#pragma once
class Serealizer
{
public:
	void Serialize(short valShort, unsigned short valUnsigned);

private:
	const char* FILENAME = "bin.txt";
};

