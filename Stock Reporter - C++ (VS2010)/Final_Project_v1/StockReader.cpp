#include "stdafx.h"

StockReader::StockReader(string inFileName) {
	fileName = inFileName;
}

Stock* StockReader::read() throw (StockInputException){
	ifstream  in;
	Stock *stocks;
	
	try {
		findLineCount();

		stocks = new Stock[count];

		in.open(fileName);

		 if (in.good()) {
			 for ( int i = 0; i < count; i++) {
				 in >> stocks[i];
			 }
		 } else {
			 throw StockInputException("Failed to open file: " + fileName);
		 }

		 in.close();
	} catch (StockInputException ex) {
		throw ex;
	}

	 return stocks;
}

void StockReader::findLineCount() throw (StockInputException) {
	string temp;
	ifstream input;
	input.open(fileName);

	count = 0;
	if (input.good()) {
		while (!input.eof()) {
			getline(input, temp);
			count++;
		}
		input.close();
	} else {
		throw StockInputException("Failed to open file: " + fileName);
	}
	
}

int StockReader::getCount() {
	return count;
}

void StockReader::setFileName(string inFileName) {
	fileName = inFileName;
}

string StockReader::getFileName() {
	return fileName;
}