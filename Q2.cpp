#include <iostream>
using namespace std;


void RowNumbers(int m, int max )                                        //RowNumber is responsible for creating each specific line for the rhombus
{                                                                       //Initially, m will start off as one, and max will change based off the PrintRhombus
    if ( m < max )
    {
        cout << m << ' ';                                               //The output of each number going up and down is printed out
        RowNumbers( m + 1, max );
    }
    cout << m << ' ';
}

void PrintRhombus(int n, int i)                                         //PrintRhombus will use the RowNumber to build the rhombus
{
    if(i == 2 * n)                                                      //This if statement will end the recursion once it occurs 2 * n
        return;                                                         //It prevents an infinite loop, as 2 * n represents how many lines the program outputs

    int numbers_in_line = i < n ? i : 2 * n - i;                        //This ternary operator ("?") will make sure the rhombus value is doing up and then going down
    int spacing = ( n - numbers_in_line ) * 2;                            //The spaces that form the triangle is calculated using the numbers

    cout << string( spacing , ' ' );                                    //This output will deal with the spacing that forms the triangle
                                                                        //Spaces is a string, but the numbers will remain an integers
    RowNumbers( 1, numbers_in_line );                                   //The RowNumbers will be called to print out the line of numbers
                                                                        //Set 1 as one of the inputs to represent the beginning of the rhombus
    cout << endl;                                                       //The endl will create a new line so that the user can see the number rhombus

    PrintRhombus( n , i + 1 );                                            //Increment i so that the numbers_in_line will eventually reach false
}

int main()
{
    int a;
    cout << "Enter a number [1-9]: " << endl;                           //Input the size of the rhombus
    cin >> a;
    if (a > 0 && a < 10)                                                //This if statement will limit the input range from 1 to 9
    {
        PrintRhombus( a, 1 );                                           //If the range is met, it will call the recursive function
    }
    else                                                                //This output will occur if the user enters a number out of range
        cout << "Wrong input, please enter a single digit number between 1 and 9." << endl;
}

//Program will terminate after one occasion, no do-while loops are being used
