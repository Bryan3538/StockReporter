//Implementation of Stock.h
#include "stdafx.h"


//****************************************************
//Constructor
//****************************************************
Stock::Stock(string insymbol, double inopenValue, double incloseValue,
		  double inhigh, double inlow, double inpreviousClose, unsigned long involume) {

	symbol = insymbol;
	openValue = inopenValue;
	closeValue = incloseValue;
	high = inhigh;
	low = inlow;
	previousClose = inpreviousClose;
	volume = involume;
	calculateChange();
}

//****************************************************
//Calculates change member variable
//****************************************************
void Stock::calculateChange() {

	if (previousClose != 0) {
		change = ((closeValue - previousClose) / previousClose) * 100;
	} else {
		change = 0;
	}
}

//****************************************************
//Accessors
//****************************************************
string Stock::getSymbol() {
	return symbol;
}

double Stock::getOpenValue() {
	return openValue;
}

double Stock::getCloseValue() {
	return closeValue;
}

double Stock::getHigh() {
	return high;
}

double Stock::getLow() {
	return low;
}

double Stock::getPreviousClose() {
	return previousClose;
}

double Stock::getChange() {
	return change;
}

unsigned long Stock::getVolume() {
	return volume;
}

//****************************************************
//Mutators
//****************************************************
void Stock::setSymbol(string insymbol) {
	symbol = insymbol;
}

void Stock::setOpenValue(double inValue) {
	openValue = inValue;
}

void Stock::setCloseValue(double inValue) {
	closeValue = inValue;
	calculateChange();
}

void Stock::setHigh(double inValue) {
	high = inValue;
}

void Stock::setLow(double inValue) {
	low = inValue;
}

void Stock::setPreviousClose(double inValue) { 
	previousClose = inValue;
	calculateChange();
}

void Stock::setVolume(unsigned long inValue) {
	volume = inValue;
}



//****************************************************
//Operator overload for input
//****************************************************
istream& operator>> (istream &in, Stock &astock) {
	in  >> astock.symbol >> astock.openValue 
		>> astock.closeValue >> astock.high 
		>> astock.low >> astock.previousClose
		>> astock.volume;

	astock.calculateChange();

	return in;
}

//****************************************************
//Operator overload for output
//****************************************************
ostream& operator<< (ostream &out, Stock &astock) {
	stringstream ss;
	ss << fixed << setprecision(2) << astock.change << "%";

	out << "|" << setw(6) << fixed << setprecision(2) << showpoint << astock.symbol
		<< "|" << setw(8) << astock.openValue
		<< "|" << setw(8) << astock.closeValue
		<< "|" << setw(9) << astock.high
		<< "|" << setw(8) << astock.low
		<< "|" << setw(9) << astock.previousClose
		<< "|" << setw(9) << ss.str();
	out.unsetf(ios_base::showpoint);
	out	<< "|" << setw(9) << astock.volume << "|";
		

	return out;
}

//****************************************************
//Overloaded Relational Operators
//****************************************************
bool Stock::operator> (Stock &astock) const {
	return symbol > astock.symbol;
}

bool Stock::operator< (Stock &astock) const{
	return symbol < astock.symbol;
}

bool Stock::operator>= (Stock &astock) const {
	return symbol >= astock.symbol;
}

bool Stock::operator<= (Stock &astock) const {
	return symbol <= astock.symbol;
}

bool Stock::operator== (Stock &astock) const {
	return symbol == astock.symbol;
}

bool Stock::operator!= (Stock &astock) const {
	return symbol != astock.symbol;
}

//****************************************************
//Sort Functions
//****************************************************
void Stock::sortBySymbol(Stock stocks[], int maxElement) {

	for(int counter = maxElement - 1; counter >= 0; counter--) {
		for(int i = 0; i < maxElement - 1; i++)
			if (stocks[i] > stocks[i + 1])
			{
				swap(stocks[i], stocks[i + 1]);
			}
	}
}

void Stock::sortByChange(Stock stocks[], int maxElement) {
	
	for(int counter = maxElement - 1; counter >= 0; counter--) {
		for(int i = 0; i < maxElement - 1; i++)
			if (stocks[i].change < stocks[i + 1].change)
			{
				swap(stocks[i], stocks[i + 1]);
			}
	}
}


