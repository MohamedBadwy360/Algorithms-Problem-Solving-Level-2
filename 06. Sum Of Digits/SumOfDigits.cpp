#include <iostream>
#include <string>

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

void PrintSumDigits(int Number)
{
    int Remainder = 0, Sum = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        Sum += Remainder;
    }

    cout << "Sum = " << Sum << endl;
}

int main()
{
    PrintSumDigits(ReadPositiveNumber("Enter Positive Number: "));

    return 0;
}