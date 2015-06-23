#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include "myFunc.h"

using namespace std;

extern const int ENTRIES = 10;
int main()
{
	initialize();																		//Print out the title for the program
	char input;																			//This will store the command
	
	double first;																		//lower bound
	double last;																		//upper bound
	double delta;																		//increment value
	do{																					//Implement a do while loop to allow the user to enter several commands
		
		cout << "Please enter command code: ";
		cin >> input;
		int count = 0;																	//This value will make sure the program does not output more than ENTRIES
//		if (input == 'Q' || input == 'q')												//This command will end the program by using "break"
//		{
//			cout << "Bye bye!" << endl;
//			break;
//		}

		if (!checkCode(input))															//The first thing the program does is to see if the user entered a valid
		{
			cout << "Invalid Input!" << endl;											//If the user did, then the program will continue
			cout << endl;																//If not, then the program will notify the user and then loop back to the beginning
			continue;																	//of the program
		}

		if (input == 'I' || input == 'i')												//For this specific input
		{
			string file_input;
			cout << "Please enter input filename: ";									//It will read a file that consists of three numbers, and then output them
			cin >> file_input;
			const char * c = file_input.c_str();										//This converts the string input to a const char *
			readDataFromFile(c);
			cout << endl;
			continue;																	//continue will jump back to the beginning of the loop
		}

		if (input == 'O' || input == 'o')
		{
			string file_output;
			cout << "Please enter output filename: ";
			cin >> file_output;
			const char * c = file_output.c_str();
			writeDataToFile(c);
			cout << endl;
			continue;
		}



		cout << "Please enter command parameters: ";
		cin >> first;
		cin >> last;
		cin >> delta;

		if (delta <= 0 || first > last)													//This will check if delta is less than 0 and if the first > last
			cout << "No computation needed" << endl;

	

		else
		{
			if (input == 'C' || input == 'c')																		//Command for circumference of radius
				for (double i = first; i < last, count < ENTRIES ; i += delta, count++)
					cout << "Circumference of circle with radius " << i << " = " << findCircumValue(i) << endl;

			else if (input == 'S' || input == 's')																	//Command for the square area value
				for (double i = first; i < last, count < ENTRIES; i += delta, count++)
					cout << "Area of square with side length " << i << " = " << findSquareAreaValue(i) << endl;

			else if (input == 'R' || input == 'r')																	//Command for square root value
				for (double i = first; i <= last, count < ENTRIES; i += delta, count++)
					cout << "Square root of " << i << " = " << findSqrtValue(i) << endl;
				
			else if (input == 'L' || input == 'l')																	//Command for lucky number
				for (double i = first; i < last, count < ENTRIES; i += delta, count++)
					cout << "Lucky number of " << i << " = " << findLuckyNumValue(i) << endl;

			else if (input == 'E' || input == 'e')
				findNextEvenValue(first, last, delta);

			else if (input == 'N' || input == 'n')																	//Command for Nyan Cat Value
				for (double i = first; i < last, count < ENTRIES; i += delta, count++)
					cout << "Nyan Cat(" << i << "): = " << findNyanCatValue(i) << endl;
	
		}
		cout << endl;
	} while (input != 'q' || input != 'Q');															//Since the only way to end the program is the quit command
																									//The user needs to enter the quit commands to end the loop
	cout << "Bye! Bye!" << endl;
	}