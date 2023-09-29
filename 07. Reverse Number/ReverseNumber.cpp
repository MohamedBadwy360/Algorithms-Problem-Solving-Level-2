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

int ReverseNumber(int Number)
{
    int Remainder = 0, Number2 = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        Number2 = Number2 * 10 + Remainder;
    }

    return Number2;
}

int main()
{
    cout << ReverseNumber(ReadPositiveNumber("Enter Positive Number: ")) << endl;;

    return 0;
}