#include "StringCheckerFrame.h"



StringCheckerFrame::StringCheckerFrame()
{
}

bool StringCheckerFrame::Start()
{
	billboard.Init();
	billboard.Start();

	return true;
}


StringCheckerFrame::~StringCheckerFrame()
{
}
