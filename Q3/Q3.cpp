#include <iostream>
#include "q3func.h"
#include "statistics.h"
using namespace std;

int main()
{
	int size;																			//Stores the size of the array

	cout << "Array size is: ";															//User can input desired array size
	cin >> size;

	int *myArray = new int[size];														//Dynamically allocate space for given array size

	DataFromFile("numbers.txt", myArray , size);										//Call DataFromFile function to generate text file of random numbers
	
	cout << "Mean is: " << getMean(myArray, size) << endl;								//Call the getMean function to get the average of the numbers in the array
	cout << "StdDev is: " << getStdDev(myArray, size) << endl;							//Call the getStdDev function to get the standard deviation of the numbers in the array
	
	cout << "Array values forward are: ";												//Prints out the array in whatever order it was generated												
		for (int i = 0; i < size; i++)
		{
			cout << myArray[i] << " ";
		}
		cout << endl;

	int temp, i;																		//Uses a second array to reverse the order of the first array
	for (i = 0; i < size / 2; ++i) 
		{
		temp = myArray[size - i - 1];
		myArray[size - i - 1] = myArray[i];
		myArray[i] = temp;																//myArray now becomes reversed
		}
		
	cout << "Array values reversed are: ";												//Print out myArray, as it has been reversed
	for (i = 0; i < size; ++i) 
		{
		cout << myArray[i] << " ";
		}
	cout << endl;


																						
	for (int i = 0; i < size ; i++)														//Program will re-use the temp array to find the largest and smallest variables
	{
		if (myArray[i] > temp)															//Go through the array, and if you find a larger number, then it replaces temp
			temp = myArray[i];
	}
	cout << "The largest array value is: " << temp << endl;


	for (int i = 0; i < size; i++)
	{
		if (myArray[i] < temp)
			temp = myArray[i];															//Go through the array, and if you find a smaller number, then it replaces temp
	}
	cout << "The smallest array value is: " << temp << endl;


	delete[] myArray;																	//Free the memory

}