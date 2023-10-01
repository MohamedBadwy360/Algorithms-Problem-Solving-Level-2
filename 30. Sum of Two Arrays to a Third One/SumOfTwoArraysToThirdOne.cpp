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

void FillArrayWithRandomNumbers(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = RandomNumber(1, 100);
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

void SumTwoArrays(int Array1[100], int Array2[100], int Array3[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array3[i] = Array1[i] + Array2[i];
    } 
}


int main()
{
    srand(unsigned(time(NULL)));

    int Array1[100], Array2[100], ArraySum[100], ArrayLength;

    ArrayLength = ReadPositiveNumber("Enter Number of Array Elements: ");

    FillArrayWithRandomNumbers(Array1, ArrayLength);
    cout << "Array1 Elemets: ";
    PrintArray(Array1, ArrayLength);

    FillArrayWithRandomNumbers(Array2, ArrayLength);
    cout << "Array2 Elemets: ";
    PrintArray(Array2, ArrayLength);

    SumTwoArrays(Array1, Array2, ArraySum, ArrayLength);
    cout << "Sum of Array1 and Array2: ";
    PrintArray(ArraySum, ArrayLength);

    return 0;
}