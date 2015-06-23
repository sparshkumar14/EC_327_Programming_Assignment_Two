#include <iostream>
#include <fstream>
#include <cstdlib> 
using namespace std;

int DatatoFile(const char *filename, int N, int M)								//This function will generate random numbers and store it in a text file
{
	ofstream myfile;															//ofstream command will write a file
	myfile.open(filename);
	for (int i = 0; i < N; i++)
		myfile << rand() % (M + 1) << endl;										//This will write a random number for every line in a given range
	myfile.close();
	return 0;
}

int DataFromFile(const char *filename, int myArray[], int &size)
{
	
	DatatoFile(filename, size, 100);									//Call the DatatoFile to generate text file filled with random numbers
	

	ifstream myfile2;													//ifstream is responsible for reading text files
	
	myfile2.open(filename);

	int n = 0;															//This number will be responsible for making slots for the array

	if (myfile2.fail())													//Checks to see if file opended
	{
		cout << "Error" << endl;
		return 1;														//No point continuing if the file didn't open
	}

	while (!myfile2.eof())												//This will go through the file until it is blank
	{
		myfile2 >> myArray[n];											//Store a number into an array slot
		n++;															//Increment n so that it can add numbers to additional slots
	}


	myfile2.close();													//Close file


	return 0;
}

