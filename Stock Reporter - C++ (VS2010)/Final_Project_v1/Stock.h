//Class to define a stock object
#ifndef H_STOCK
#define H_STOCK

#include "stdafx.h"

class Stock {

	//****************************************************
	//Overloaded Stream Operators
	//****************************************************
	friend istream& operator>> (istream &in, Stock &astock);
	friend ostream& operator<< (ostream &out, Stock &astock);

public:

	//****************************************************
	//Constructors
	//****************************************************
	Stock(string insymbol = "", double inopenValue = 0, double incloseValue = 0,
		  double inhigh = 0, double inlow = 0, double inpreviousClose = 0,
		  unsigned long involume = 0);
	//Postcondition: symbol = insymbol
	//				 openValue = inopenValue
	//               closeValue = incloseValue
	//			     high = inhigh
	//				 low = inlow
	//				 previousClose = inpreviousClose
	//				 volume = inVolume
	//				 change is calculated through the calculateChange method

	//****************************************************
	//Accessors
	//****************************************************
	string getSymbol();
	double getOpenValue();
	double getCloseValue();
	double getHigh();
	double getLow();
	double getPreviousClose();
	double getChange();
	unsigned long getVolume();

	//****************************************************
	//Mutators
	//****************************************************
	void setSymbol(string insymbol);       //Postcondition: symbol = insymbol
	void setOpenValue(double inValue);     //Postcondition: openValue = inValue
	void setCloseValue(double inValue);    //Postcondition: closeValue = inValue
	void setHigh(double inValue);          //Postcondition: high = inValue
	void setLow(double inValue);		   //Postcondition: low = inValue
	void setPreviousClose(double inValue); //Postcondition: previousClose = inValue
	void setVolume(unsigned long inValue); //Postcondition: volume = inValue

	//****************************************************
	//Overloaded Relational Operators
	//****************************************************
	bool operator> (Stock &astock) const;
	bool operator< (Stock &astock) const;
	bool operator>= (Stock &astock) const;
	bool operator<= (Stock &astock) const;
	bool operator== (Stock &astock) const;
	bool operator!= (Stock &astock) const;

	//****************************************************
	//Sort Functions
	//****************************************************
	static void sortBySymbol(Stock stocks[], int maxElement);
	static void sortByChange(Stock stocks[], int maxElement);

private:
	//Ticker symbol
	string symbol;
	//Open and close prices
	double openValue;
	double closeValue;
	//Highest achieved price
	double high;
	//Lowest price of the day
	double low;
	//Closing price for the previous day
	double previousClose;
	//Percent change from yesterday to today
	double change;
	//Number of shares traded today
	unsigned long volume;
	//Calculates Change Percentage
	void calculateChange();
};

#endif