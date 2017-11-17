#include "MainFrame.h"



MainFrame::MainFrame()
{
	mode = 0;
}

int MainFrame::Process()
{
	switch (mode) {
	case -1:
	case 0:
		simulatorframe.Process();
	}
	return mode;
}

MainFrame::~MainFrame()
{
}
