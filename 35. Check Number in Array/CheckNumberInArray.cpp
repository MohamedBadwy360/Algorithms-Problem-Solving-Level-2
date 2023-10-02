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

void FillArrayWithRandomNumbers(int Array[100], int &ArrayLength)
{
    cout << "Enter Array Length: ";
    cin >> ArrayLength;

    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = RandomNumber(1, 100);
    }
    
    cout << "----------------------\n";
}

void PrintArray(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }

    cout << "\n----------------------\n";
}

short FindNumberIndexInArray(int Array[100], int ArrayLength, int Number)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if (Number == Array[i])
            return i;
    }

    return -1;
}

bool CheckNumberInArray(int Array[100], int ArrayLength, int Number)
{
    return (FindNumberIndexInArray(Array, ArrayLength, Number) == -1);
}

int main()
{
    srand(unsigned(time(NULL)));

    int Array[100], ArrayLength;

    FillArrayWithRandomNumbers(Array, ArrayLength);
    PrintArray(Array, ArrayLength);

    int Number = ReadPositiveNumber("Enter Number to search for: ");

    cout << "Number to serach for is: " << Number << endl;

    if (CheckNumberInArray(Array, ArrayLength, Number))
        cout << "Number is not found.\n";
    else 
        cout << "Number is found.\n";
    
    return 0;
}