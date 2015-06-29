#ifndef H_STOCKREADER
#define H_STOCKREADER

#include "stdafx.h"

class StockReader {

public:
	StockReader(string inFileName = "StockInput.txt");
	Stock* read();
	int getCount();
	void setFileName(string);
	string getFileName();

private:
	string fileName;
	int count;
	void findLineCount();
};

#endif