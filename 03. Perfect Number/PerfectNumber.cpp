#include <iostream>
#include <cmath>

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

bool CheckPerfectNumber(int Number)
{
    int HalfNumber = round(Number / 2);
    int Sum = 0;

    for (int Counter = 1; Counter <= HalfNumber; Counter++)
    {
        if (Number % Counter == 0)
            Sum += Counter;
    }

    return (Sum == Number);
}

void PrintPerfectOrNot(int Number)
{
    if (CheckPerfectNumber(Number))
        cout << Number << " is perfect number.\n";
    else    
        cout << Number << " is not perfect number.\n";
}

int main()
{
    // int Number = ReadPositiveNumber("Enter Positive Number: ");

    PrintPerfectOrNot(ReadPositiveNumber("Enter Positive Number: "));

    return 0;
}