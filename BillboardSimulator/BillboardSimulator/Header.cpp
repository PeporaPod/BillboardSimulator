#include "Header.h"



int My_stoi(std::string string)
{
	int integer;
	try {
		integer = std::stoi(string);
	}
	catch (std::invalid_argument) {
		return 255;
	}
	return integer;
}