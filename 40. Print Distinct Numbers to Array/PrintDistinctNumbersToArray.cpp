#include <iostream>

using namespace std;

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

short FindNumberIndexInArray(int Array[100], int ArrayLength, int Number)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if (Number == Array[i])
            return i;
    }

    return -1;
}

bool CheckNumberInArray(int Number, int Array[100], int ArrayLength)
{
    return (FindNumberIndexInArray(Array, ArrayLength, Number) != -1);
}

void CopyDistinctNumbers(int SourceArray[100], int DestinationArray[100], int ArrayLength, int &Array2Length)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if(!CheckNumberInArray(SourceArray[i], DestinationArray, Array2Length))
            AddArrayElement(SourceArray[i], DestinationArray, Array2Length);
    }
}


int main()
{
    int Array[100] = {10, 10, 10, 50, 50, 50, 70, 90, 90, 90};
    int ArrayLength = 10;
    int Array2[100], Array2Length = 0;

    cout << "Array1 Elements: \n"; 
    PrintArray(Array, ArrayLength);

    CopyDistinctNumbers(Array, Array2, ArrayLength, Array2Length);

    cout << "Array2 Elements: \n"; 
    PrintArray(Array2, Array2Length);
    return 0;
}