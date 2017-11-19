#include "StringList.h"



StringList::StringList()
{
	for (int i = 1; LoadBinaryString(vecstrinfo, i); i++);
}

StringList::~StringList()
{
}
