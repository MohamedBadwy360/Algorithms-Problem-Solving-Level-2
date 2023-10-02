#include <iostream>
#include <cstdlib>

using namespace std;

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

void AddArrayElement(int Number, int Array[100], int &ArrayLength)
{
    ArrayLength++;
    Array[ArrayLength - 1] = Number;
}

void PrintArray(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }

    cout << "\n----------------------\n";
}

void CopyArray(int SourceArray[100], int DestinationArray[100], int ArrayLength, int Array2Length)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        AddArrayElement(SourceArray[i], DestinationArray, Array2Length);
    }
}


int main()
{
    srand(unsigned(time(NULL)));

    int Array[100], Array2[100], ArrayLength = 0, Array2Length = 0;

    FillArrayWithRandomNumbers(Array, ArrayLength);
    cout << "Array 1 Elements: ";
    PrintArray(Array, ArrayLength);

    CopyArray(Array, Array2, ArrayLength, Array2Length);
    cout << "Array 2 Elements: ";
    PrintArray(Array, ArrayLength);

    return 0;
}