#include <iostream>
#include <cstdlib>

using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;

    do
    {
        cout << Message << endl;
        cin >> Number;
        cout << "----------------------\n";
    }
    while (Number <= 0);

    return Number;
}

int RandomNumber(int From, int To)
{
    return (rand() % (To - From + 1) + From);
}

void SwapNumbers(int &Num1, int &Num2)
{
    int Temp;
    Temp = Num1;
    Num1 = Num2;
    Num2 = Temp;
}

void FillArrayWith1ToN(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = i + 1;
    }
}

void PrintArray(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }

    cout << "\n----------------------\n";
}

void ShuffleArray(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        SwapNumbers(Array[RandomNumber(0, ArrayLength-1)], Array[RandomNumber(0, ArrayLength-1)]);
    } 
}


int main()
{
    srand(unsigned(time(NULL)));

    int Array[100], ArrayLength;

    ArrayLength = ReadPositiveNumber("Enter Number of Array Elements: ");

    FillArrayWith1ToN(Array, ArrayLength);
    cout << "Array Elemets: \n";
    PrintArray(Array, ArrayLength);

    ShuffleArray(Array, ArrayLength);
    cout << "Shuffled Array Elemets: \n";
    PrintArray(Array, ArrayLength);

    return 0;
}