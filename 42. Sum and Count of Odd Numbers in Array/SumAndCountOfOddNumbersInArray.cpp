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
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }

    cout << "\n----------------------\n";
}

int SumOddArrayNumbers(int Array[100], int ArrayLength)
{
    int Sum = 0;

    for (int i = 0; i < ArrayLength; i++)
    {
        if (Array[i] % 2 != 0)
            Sum += Array[i];
    }
    
    return Sum;
}

int CountOdd(int Array[100], int ArrayLength)
{
    int Counter = 0;

    for (int i = 0; i < ArrayLength; i++)
    {
        if (Array[i] % 2 != 0)
            Counter++;
    }
    
    return Counter;
}

int main()
{
    srand(unsigned(time(NULL)));

    int Array[100], ArrayLength;

    FillArrayWithRandomNumbers(Array, ArrayLength);
    cout << "Array Elements: \n";
    PrintArray(Array, ArrayLength);

    cout << "Sum Odd Numbers = " << SumOddArrayNumbers(Array, ArrayLength) <<endl;
    cout << "Count Odd Numbers = " << CountOdd(Array, ArrayLength) <<endl;

    return 0;
}