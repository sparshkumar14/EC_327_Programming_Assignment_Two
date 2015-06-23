#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <cmath>


using namespace std;
const int ENTRIES = 10;


void initialize()														//Print out information at the beginning of the program
{
	cout << "EC327: Introduction to Software Engineering" << endl;
	cout << "Fall 2014" << endl;
	cout << "Programming Assignment 2" << endl;
	cout << "Maximum computation is: " << ENTRIES << endl;
	cout << endl;
}

bool checkCode(char input)								//Checks to see if the user is entering valid characters
{
	if (input == 'S' || input == 's')
		return true;
	else if (input == 'C' || input == 'c')
		return true;
	else if (input == 'R' || input == 'r')
		return true;
	else if (input == 'E' || input == 'e')
		return true;
	else if (input == 'L' || input == 'l')
		return true;
	else if (input == 'N' || input == 'n')
		return true;
	else if (input == 'I' || input == 'i')
		return true;
	else if (input == 'O' || input == 'o')
		return true;
	else
		return false;
}

double findCircumValue(double first)												//Calculates the circumference
{
	return (2 * first * 3.14);
}

double findSquareAreaValue(double first)											
{
	return pow(first, 2);
}

double findSqrtValue(double first)
{
	return sqrt(first);
}

double findLuckyNumValue(double first)
{
	int first_int = (unsigned)(int)first;							//Narrowing type
	return rand();
	srand(first_int);												//Makes sure that each random number is distinct
}

int findNextEvenValue(double first, double last, double delta)
{
	int count = 0;
	for (double i = first; i < last, count < ENTRIES; i += delta, count++)
	{
		int j = round(i);
		if (j % 2 == 1)
		{
			j++;
			cout << "Next even number for " << i << " = " << j << endl;
		}
		else if (j % 2 == 0)
		{
			cout << "Next even number for " << i << " = " << j << endl;
		}
	}
	return 0;
}

void readDataFromFile(const char * input_file)													//Uses file I/O
{

	ifstream input(input_file);

	double start;
	double finish;
	double step;

	input >> start;
	input >> finish;
	input >> step;

	cout << "Successfully read data from file: Start " << start << " Finish " << finish << " Step " << step << "." << endl;


	


}

double findNyanCatValue(double first)
{
	return pow((2 * first), first);														//Return math operation
}

void writeDataToFile(const char * file_output)
{
	const double first = rand() % 11;													//The rand sets the parameters for the three inputs for the nyanCat function
	const double last = rand() % 30 + 20;
	const double step = rand() % 10 + 5;
	int count = 0;
	ofstream output(file_output);

	for (double i = first; i < last, count < ENTRIES; i += step, count++)
		output << "Nyan Cat(" << i << "): = " << findNyanCatValue(i) << endl;

	output.close();
	cout << "File has been written" << endl;											//Gives confirmation

}

