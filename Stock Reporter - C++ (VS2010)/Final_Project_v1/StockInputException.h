#ifndef H_StockInputException
#define H_StockInputException

#include "stdafx.h"

class StockInputException: public exception {

public:
	StockInputException(string inmessage = "");
	string what();

private:
	string message;
};

#endif