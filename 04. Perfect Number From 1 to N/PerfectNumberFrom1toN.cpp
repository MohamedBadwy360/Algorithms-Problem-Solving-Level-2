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

void PerfectNumbersFrom1toN(int N)
{
    cout << "\nPerfect Numbers From 1 to " << N << " is: \n"; 
    for (int Number = 1; Number <= N; Number++)
    {
        if (CheckPerfectNumber(Number))
            cout << Number << endl;
    }
}

int main()
{
    // int Number = ReadPositiveNumber("Enter Positive Number: ");

    PerfectNumbersFrom1toN(ReadPositiveNumber("Enter Positive Number N: "));

    return 0;
}