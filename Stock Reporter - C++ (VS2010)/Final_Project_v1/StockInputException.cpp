#include "stdafx.h"

StockInputException::StockInputException(string inmessage) {
	message = "StockInputException: ";
	if (inmessage != "") {
		message.append(inmessage);
	} else {
		"An error occured while trying to read stock data from your input file.";
	}
}

string StockInputException::what() {
	return message;
}