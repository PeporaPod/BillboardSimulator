#pragma once
#include "Billboard.h"
class MainFrame
{
private:
	Billboard billboard;	//�d���f����
public:
	MainFrame();
	bool Start();
	bool Process();
	~MainFrame();
};

