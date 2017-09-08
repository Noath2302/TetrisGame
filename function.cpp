#include "function.h"

std::string IntToString(int a)
{
	std::ostringstream temp;
	temp << a;
	return temp.str();
};

int charToInt(const char* value){
std::stringstream strValue;
strValue << value;

unsigned int intValue;
strValue >> intValue;
return intValue;
}