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

void PrintNumberPattern(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(64 + i);
        }
        
        cout << endl;
    }
}

int main()
{
    PrintNumberPattern(ReadPositiveNumber("Enter Positive Number: "));

    return 0;
}