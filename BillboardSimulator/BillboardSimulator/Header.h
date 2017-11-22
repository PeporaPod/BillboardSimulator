#pragma once
#include <vector>


const int SCREENWIDTH_MAIN				=  640;
const int SCREENHEIGHT_MAIN				=  480;
const int SCREENWIDTH_SIMULATOR			= 1600;
const int SCREENHEIGHT_SIMULATOR		=  800;
const int SCREENWIDTH_STRINGDISPLAY		= 1500;
const int SCREENHEIGHT_STRINGDISPLAY	=  600;
const int COLORBITDEPTH					=   32;
const int LED_RADIUS					=    2;
const int LED_ROW						=   16;
const int LED_COLUMN					=   64;


typedef struct LED {
	int x, y;
	unsigned int color;
}LED;
typedef std::vector<LED>				LED_ARRAY;
typedef std::vector<std::vector<LED>>	LED_MATRIX;