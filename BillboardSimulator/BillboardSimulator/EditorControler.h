#pragma once
#include "Billboard.h"
#include <vector>
class EditorControler
{
private:
	int cursor_x;
	int cursor_y;
	std::vector<int> axis_x;
	std::vector<int> axis_y;
public:
	EditorControler();
	void Init(Billboard billboard);
	~EditorControler();
};

