#include <iostream>

using namespace std;

struct Array
{
    int Array[100];
};

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

Array EnterArrayElements(int NumberOfElements, Array Array)
{
    cout << "Enter Array Elements: \n";

    for (short i = 0; i < NumberOfElements; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> Array.Array[i];
    }
    cout << "----------------------\n";

    return Array;
}

void CheckNumberInArray(int Number, int NumberOfElements, Array Array)
{
    short Counter = 0;

    cout << "Original Array: ";
    for (short i = 0; i < NumberOfElements; i++)
    {
        cout << Array.Array[i] << " ";

        if (Number == Array.Array[i])
            Counter++;
    }

    cout << endl << Number << " is Repeated " << Counter << " times.\n";
}


int main()
{
    int NumberOfElements = ReadPositiveNumber("Enter Number of Elements: ");

    Array Array;
    Array = EnterArrayElements(NumberOfElements, Array);

    int Number = ReadPositiveNumber("Enter the number you want to check: ");

    CheckNumberInArray(Number, NumberOfElements, Array);

    return 0;
}