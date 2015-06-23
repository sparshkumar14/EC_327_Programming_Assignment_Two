#include <cmath>

float getMean(int myArray[], int size)
{
	//The average may not necessarily be an integer
	float avg = 0.0;
	float sum = 0.0;
	for (int i = 0; i < size; ++i)
	{
		sum += myArray[i];													//Add each number of the array to the sum variable
	}
	avg = ((float)sum) / size;												//Calculate the average by dividing the sum by the array size
	return avg;
}


float getStdDev(int myArray[], int size)
{
	//Call getMean function to get the average value for the calculations
	float sum = 0;
	float avg = getMean(myArray, size);											//Get the average value from the getMean function
	for (int l = 0; l < size; l++)
	{
		sum += (myArray[l] - avg) * (myArray[l] - avg);							//Multiply the difference between the value in array and average, and then add
	}																			//it to the sum. There is no need for the pwr() function from cmath

	return sqrt ( sum / size);													//Perfrom final function by taking the square root of the sum divided by the size

}



