#include <iostream>
#include <cmath>

using namespace std;

enum enPrime {NotPrime, Prime};

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

enPrime CheckPrime(int Number)
{
    int HalfNumber = round(Number / 2);

    for (int Counter = 2; Counter <= HalfNumber; Counter++)
    {
        if (Number % Counter == 0)
            return enPrime::NotPrime;
    }

    return enPrime::Prime;
}

void PrimeNumbersFrom1toN(int N)
{
    cout << "\nPrime Numbers From 1 to " << N << " is: \n"; 
    for (int Number = 1; Number <= N; Number++)
    {
        if (CheckPrime(Number) == enPrime::Prime)
            cout << Number << endl;
    }
}

int main()
{
    int Number = ReadPositiveNumber("Enter Postive Number N: ");

    PrimeNumbersFrom1toN(Number);

    return 0;
}