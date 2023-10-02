#include <iostream>

using namespace std;

int ReadNumber()
{
    int Number;
    cout << "Enter a number: ";
    cin >> Number;

    return Number;
}

void AddArrayElement(int Number, int Array[100], int &ArrayLength)
{
    ArrayLength++;
    Array[ArrayLength - 1] = Number;
}

void InputUserNumbersInArray(int Array[100], int &ArrayLength)
{
    bool AddMore = true;
    do 
    {
        AddArrayElement(ReadNumber(), Array, ArrayLength);
        cout << "Do you need to add more elements [0/1]? ";
        cin >> AddMore;
    }
    while(AddMore);
}

void PrintArray(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }

    cout << "\n----------------------\n";
}


int main()
{
    int Array[100], ArrayLength = 0;

    InputUserNumbersInArray(Array, ArrayLength);

    cout << "Array Length: " << ArrayLength << endl;
    cout << "Array Elements: ";
    PrintArray(Array, ArrayLength);

    return 0;
}