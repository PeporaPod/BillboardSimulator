#pragma once
#include "Header.h"
class StringList
{
private:
	std::vector<StringInformation> number_string;
	std::vector<StringInformation> stringlist;

	std::string StringToFilePass(std::string string);
	bool AddNumberString(std::string SEG_FilePass);
	bool SetNumberString(LEDTABLE& billboard, int id, int x, int y);
	bool AddString(PCHAR string, int red, int green, int blue);
public:
	StringList();
	bool	Init();
	bool	Add_Single(PCHAR string, int red, int green, int blue);
	int		Add_Multiple(PCHAR ENUM_File);
	bool	Draw(LEDTABLE& ledtable, TABLESIZE tablesize, int id, int x, int y, bool english_trigger);
	bool	SetDepartureTime(LEDTABLE& billboard, int time, int x, int y);
	int		GetID(std::string string);
	~StringList();
};

