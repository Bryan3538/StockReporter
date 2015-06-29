#include "stdafx.h"


Writer::Writer() {
	createDateString();
}

void Writer::createDateString() {
	stringstream ss;
	time_t t = time(0);
	struct tm *now = localtime(&t);

	ss << now->tm_year + 1900 
	   << setw(2) << setfill('0') << now->tm_mon + 1 
	   << setw(2) << now->tm_mday << ".txt";

	fileName = ss.str();
}

string Writer::getFileName() {
	return fileName;
}

bool Writer::writeFileReport(Stock stocks[], int max) {
	   ofstream output;
	   output.open(fileName);
	
	if (output.good()){
		Stock::sortBySymbol(stocks, max);
		output << "Report by Symbols" << endl << endl;
		writeReport(output, stocks, max);
		output << endl;
		Stock::sortByChange(stocks, max);
		output << "Report by Change" << endl;
		output << endl;
		writeReport(output, stocks, max);
		output.close();
		cout << "The file has successfully been printed. " << endl;
		return true;
	} else {
		output.close();
		cout << "File Error in Output System: Writer::writeFileReport" << endl;
		return false;
	}
}

void Writer::writeScreenReport(Stock stocks[], int max) {
	Stock::sortBySymbol(stocks, max);
	cout << "Report by Symbols" << endl << endl;
	writeReport(cout, stocks, max);
	cout << endl;
	Stock::sortByChange(stocks, max);
	cout << "Report by Change" << endl << endl;
	writeReport(cout, stocks, max);
}

void Writer::writeReport(ostream &out, Stock stocks[], int max) {
	writeHeader(out);	
	for (int i = 0; i < max; i++) {
			out << stocks[i] << endl;
			writeDivider(out);
			out << endl;
	}
}

void Writer::writeHeader(ostream &out) {
		out << left << setw(22) << "Stock"
			 << setw(24) << "Today"
			 << setw(10) << "Previous"
			 << setw(10) << "Percent" << endl;
		out << left << setw(10)  << "Symbol"
			 << setw(9) << "Open"
			 << setw(10) << "Close"
	 		 << setw(10) << "High"
			 << setw(7) << "Low"
			 << setw(10) << "Close"
			 << setw(11) << "Change"
			 << setw(12) << "Volume" << endl;
		out << setw(75) << setfill('-') << "" << endl;
		out.unsetf(ios::left);
		out << setfill(' ');
}

void Writer::writeDivider(ostream &out) {
	out << "|------"
		<< "+--------"
		<< "+--------"
		<< "+---------"
		<< "+--------"
		<< "+---------"
		<< "+---------"
		<< "+---------|";
}