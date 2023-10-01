#include <iostream>

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

void ReadArray(int Array[100], int &ArrayLength)
{
    cout << "Enter Array Length: ";
    cin >> ArrayLength;
    cout << "----------------------\n";

    cout << "Enter Array Elements: \n";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> Array[i];
    }
    
    cout << "----------------------\n";
}

void PrintArray(int Array[100], int ArrayLength)
{
    cout << "Original Array: ";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }

    cout << "\n----------------------\n";
}

short TimesRepeated(int Number, int Array[100], int ArrayLength)
{
    short Counter =0;

    for (int i = 0; i < ArrayLength; i++)
    {
        if (Number == Array[i])
            Counter++;
    }

    return Counter;
}

int main()
{
    int Array[100], ArrayLength;

    ReadArray(Array, ArrayLength);
    PrintArray(Array, ArrayLength);
    
    int Number = ReadPositiveNumber("Enter the number you want to check: ");

    cout << Number << " is repeated " << TimesRepeated(Number, Array, ArrayLength) << " time(s)\n";

    return 0;
}