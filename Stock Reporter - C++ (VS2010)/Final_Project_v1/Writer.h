//class to define a writer
#ifndef H_Writer
#define H_Writer

#include "stdafx.h"

class Writer {

public:
	Writer();
	bool writeFileReport(Stock stocks[], int max);
	void writeScreenReport(Stock stocks[], int max);
	string getFileName();
	
private: 
	string fileName;
	void writeReport(ostream&, Stock[], int);
	void createDateString();
	void writeHeader(ostream&);
	void writeDivider(ostream&);
};

#endif