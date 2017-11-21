#pragma once
#include <DxLib.h>
#include "Billboard.h"
class StringDisplayFrame
{
private:
	Billboard* billboard;
public:
	StringDisplayFrame();
	void Start();
	~StringDisplayFrame();
};

