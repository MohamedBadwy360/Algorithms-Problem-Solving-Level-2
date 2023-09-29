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

int DigitFrequency(int Number, short Digit)
{
    int Remainder = 0, Counter = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        
        if (Remainder == Digit)
            Counter++;
    }

    return Counter;
}

int main()
{
    int Number = ReadPositiveNumber("Enter Positive Number: ");
    short Digit = ReadPositiveNumber("Enter Positive Digit: ");

    cout << "Frequency of " << Digit << " in " << Number << " is: " 
         << DigitFrequency(Number, Digit) << endl;

    return 0;
}