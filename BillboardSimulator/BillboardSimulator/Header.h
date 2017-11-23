#pragma once
#include <vector>


const int SCREENWIDTH_MAIN				=  640;
const int SCREENHEIGHT_MAIN				=  480;
const int SCREENWIDTH_SIMULATOR			= 1600;
const int SCREENHEIGHT_SIMULATOR		=  800;
const int SCREENWIDTH_STRINGDISPLAY		= 1500;
const int SCREENHEIGHT_STRINGDISPLAY	=  600;
const int SCREENWIDTH_STRINGEDITOR		= 1600;
const int SCREENHEIGHT_STRINGEDITOR		=  800;
const int COLORBITDEPTH					=   32;
const int LED_RADIUS					=    2;
const int LED_ROW						=   16;
const int LED_COLUMN					=   64;
const int STRING_LENGTH					=   24;


typedef struct TrainInformation {
	int line_id;
	int type_id;
	int destination_id;
}TrainInformation;


typedef struct TrainInformationAsString {
	std::vector<std::string> line;
	std::vector<std::string> type;
	std::vector<std::string> destination;
}TrainInformationAsString;


typedef struct StringInformation {
	char string[STRING_LENGTH] = { NULL };
	int width = LED_COLUMN;
	char type = '?';
	unsigned __int8 R = 32, G = 32, B = 32;
	unsigned long long led_status[LED_ROW] = { 0 };
}StringInformation;