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

void PrintArray(int Array[100], int ArrayLength)
{
    cout << "Array Elements: ";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }

    cout << "\n----------------------\n";
}

int MaxArrayNumber(int Array[100], int ArrayLength)
{
    int MaxNumber = 0;

    for (int i = 0; i < ArrayLength; i++)
    {
        if (MaxNumber < Array[i])
            MaxNumber = Array[i];
    }

    return MaxNumber;
}

int main()
{
    srand(unsigned(time(NULL)));

    int Array[100], ArrayLength;

    FillArrayWithRandomNumbers(Array, ArrayLength);
    PrintArray(Array, ArrayLength);

    cout << "Max number in array is: " << MaxArrayNumber(Array, ArrayLength) << endl;

    return 0;
}