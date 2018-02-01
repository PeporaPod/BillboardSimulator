#pragma once
#include "Header.h"
class LineControler
{
private:
	std::vector<LineInformation> veclineinfo;
public:
	LineControler();
	int Init();
	LineInformation GetLineInformation(int id);
	int GetLineID(std::string str);
	~LineControler();
};

