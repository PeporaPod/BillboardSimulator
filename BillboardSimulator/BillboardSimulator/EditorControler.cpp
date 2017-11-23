#include "EditorControler.h"



EditorControler::EditorControler()
{
	cursor_x = 0;
	cursor_y = 0;
}

void EditorControler::Init(Billboard billboard)
{
	billboard.GetAxis(axis_x, axis_y);
}


EditorControler::~EditorControler()
{
}
