//C++ Final Project
//Abdel Asimahmoud
//Joe Colling
//Bryan Fulton
//Kyle Perenchio
//Reads in a file of stock data, StockInput.txt, and generates reports of its data
//Reports include both file and console reports
//Sorted by change as well as symbol


//COMPILED VERSION

#include "stdafx.h"
using namespace System;

void mainMenu();
void resizeWindow();
int getInt(string prompt);
int getInt(string prompt, int min, int max);
void viewReports(Writer &writer, Stock stocks[], int max);
void printReports(Writer &writer, Stock stocks[], int max);
string getFileNameFromUser(string);



int main() {
	resizeWindow();
	mainMenu();

	return 0;
}

//Resizes console window
void resizeWindow() {
	int origHeight = Console::WindowHeight;
	int origWidth = Console::WindowWidth;
	int height = (int)(origHeight * 2.2);
	int width = (int)(origWidth * 1.5);
	Console::SetWindowSize(width, height);
}

void mainMenu() {

	int decision;
	bool exit;
	Writer writer;
	Stock *stocks;
	StockReader reader;

	try {
		stocks = reader.read();
	} catch (string ex) {
		cout << ex << endl;
		cout << "Please enter a valid file using the menu option." << endl;
	}


	do {
		try {
			cout << "************************************************************" << endl
				 << "*                  First Investor's Heaven                 *" << endl
				 << "*                        Investments                       *" << endl
				 << "*                          Trading                         *" << endl
				 << "*                          Success                         *" << endl
				 << "************************************************************" << endl
				 << endl << endl;
			cout << "Welcome to the First Investor's Heaven stock reporter." << endl;
			cout << "Please select one of the following options." << endl << endl;
			cout << "(1) View Reports" << endl;
			cout << "(2) Print Reports to File" << endl;
			cout << "(3) Change Input File" << endl;
			cout << "(4) Exit" << endl << endl;
			decision = getInt("Your selection: ", 1, 4);

			switch(decision) {
			case 1: 
				viewReports(writer, stocks, reader.getCount());
				break;
			case 2:
				printReports(writer, stocks, reader.getCount());
				break;
			case 3:
				system("cls");
				reader.setFileName(getFileNameFromUser(reader.getFileName()));
				system("cls");
				stocks = reader.read();
				break;
			case 4:
				exit = true;
				delete[] stocks;
				break;
			default:
				cout << "An error has occured, please try again." << endl;
			}
		} catch (StockInputException ex) {
			cout << ex.what() << endl << endl;
			reader.setFileName(getFileNameFromUser(reader.getFileName()));
		}
	} while (!exit);

}

void viewReports(Writer &writer, Stock stocks[], int max) {
	writer.writeScreenReport(stocks, max);
	cout << "Press enter to return to main menu." << endl;
	cin.ignore(1000, '\n');
	system("cls");
}

void printReports(Writer &writer, Stock stocks[], int max) {
    int view = 0;
	bool success = writer.writeFileReport(stocks, max);
	
	if (success) {
		cout << endl << "Would you like to view the report?" << endl << endl;
		cout << "(1) Yes" << endl;
		cout << "(2) No" << endl << endl;
		view = getInt("Your selection: ", 1, 2);
	}

	if (view == 1 && success) {
		string systemMessage = "notepad.exe ";
		string fileName = writer.getFileName();
		systemMessage.append(fileName);
		system(systemMessage.c_str());
	} 

	system("cls");
}

int getInt(string prompt) {
	int value;
	bool isValid = false;
	string invalidInput = "You may only enter numbers!";

	do {
		try {
			cout << prompt;
			cin >> value;
			cin.ignore(1000, '\n');
			cout << endl;

			if (!cin) {
				throw invalidInput;
			}

			isValid = true;
		} catch (string message) {
			cout << message << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while(!isValid);
	
	return value;
}

int getInt(string prompt, int min, int max) {
	int value;
	bool isValid = false;

	do {
		value = getInt(prompt);

		if(value < min || value > max) {
			cout << "The number must be between " << min
				 << " and " << max << "!" << endl;
		}else {
			isValid = true;
		}
	} while(!isValid);
	
	return value;
}

string getFileNameFromUser(string currentFileName) {
	string fileName = "";
	string defaultFileName = "StockInput.txt";

	
	cout << "You are currently using the file: " << currentFileName << endl << endl
	     << "- Please enter the path for the input file you wish to use." << endl << endl
		 << "- Hit enter without typing a path to continue using the current file." << endl << endl
		 << "- Enter the word 'default' to revert to the default file name." << endl << endl
		 << "New File Path: ";
	getline(cin, fileName, '\n');
	cout << endl;

	

	if (fileName == "") {
		fileName = currentFileName;
	} else {
		string lowercaseInput = fileName;
		transform(lowercaseInput.begin(), lowercaseInput.end(), lowercaseInput.begin(), tolower);
		if (lowercaseInput == "default") {
			fileName = defaultFileName;
		}
	}

	return fileName;
}