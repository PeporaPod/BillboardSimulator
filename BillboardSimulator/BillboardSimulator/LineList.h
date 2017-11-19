#pragma once
#include "Header.h"
class LineList
{
private:
	LINELIST linelist;
	bool Process(std::list<std::string> element);
public:
	LineList();
	int		Init();
	void	Set(LED_MATRIX& led_table, TABLESIZE table_size, int line_id, int y);
	int		GetID(std::string line_name);
	~LineList();
};

