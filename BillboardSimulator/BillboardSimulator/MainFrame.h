#pragma once
#include <DxLib.h>
#include "ModeSelectorFrame.h"
#include "StringDisplayFrame.h"
class MainFrame
{
	int mode;
	ModeSelectorFrame* modeselectorframe;
	StringDisplayFrame* stringdisplayframe;
public:
	MainFrame();
	void Start();
	~MainFrame();
};

