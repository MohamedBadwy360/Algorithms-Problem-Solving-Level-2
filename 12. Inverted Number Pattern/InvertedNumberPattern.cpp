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

void InvertedNumberPattern(int Number)
{
    for (int i = Number; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << i;
        }
        
        cout << endl;
    }
}

int main()
{
    InvertedNumberPattern(ReadPositiveNumber("Enter Positive Number: "));

    return 0;
}