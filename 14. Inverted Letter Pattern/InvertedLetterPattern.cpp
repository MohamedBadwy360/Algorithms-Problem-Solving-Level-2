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

void PrintLetterPattern(int Number)
{
    for (int i = Number; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << char(i + 64);
        }
        
        cout << endl;
    }
}

int main()
{
    PrintLetterPattern(ReadPositiveNumber("Enter Positive Number: "));

    return 0;
}