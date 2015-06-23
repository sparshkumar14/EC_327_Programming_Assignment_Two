#include <iostream>

using namespace std;

int * DoubleandReverse (int *list, int size)                        //Function that will calculate the new array
{
    int* result = new int[size];                                    //Create the new array, and dynamically allocate the memory for the size of the new array
        for (int i = 0; i < size - 1; i++)                          //This first for loop will store the values of the original array in the new array
        {
            result[i] = list[i];                                    //Therefore the first half of the new array will be a copy of the original array
        }

        for (int i = 0, j = size - 1; i < size*.5; i++, j--)        //This for loop will fill the second half of the new array with the reversed version
        {                                                           //Using a second variable, the loop will go backwards and store the reversed values
            result[j] = list[i];                                    //in the other half of the new array
        }

    cout << "Final Array is: ";
    for (int i = 0; i < size; i++)                                  //Loop will output the new array
        cout << result[i] << " ";
        cout << "and the address of zero element is: " << &result;  //This line will print out the address of the second array
    cout << endl;
}


int main ()
{
  int i,n;

    cout << "Enter the number of entries: ";                            //Input the size of the original array
    cin >> i;                                                           //This will be the size of the original array
    int * list = new int[i];                                            //Dynamically allocate space for the first array

    for (n = 0;  n < i ; n++)                                           //Use a for loop to input the values in the first array
    {
      cout << "Entry " << n << " is" << ": ";
      cin >> list[n];
    }
    cout << "Original Array is: ";                                      //I use a for loop to display the original array
    for (n = 0; n < i ; n++)
      cout << list[n] << " ";
              cout << "and the address of zero element is: " << &list;  //This line output the hex address
    cout << endl;

    DoubleandReverse (list, 2*i);                                       //The first input in the function is the original array
                                                                        //The second input is the size of the new array.
  return 0;                                                             //I multiply it by 2 because the second array will be double the original size
}
