#pragma once
#include "Header.h"



bool Check_StringToInt(std::string string) {
	if (string.empty()) return false;
	for (unsigned int i = 0; i < string.size(); i++) {
		if ('0' <= string[i] && string[i] <= '9');
		else return false;
	}
	return true;
}