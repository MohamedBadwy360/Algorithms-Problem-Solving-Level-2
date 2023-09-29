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

void ReverseNumber(int Number)
{
    string StringNumber = to_string(Number);

    for (int i = StringNumber.length() - 1; i >= 0; i--)
    {
        cout << StringNumber[i] << endl;
    }
}

int main()
{
    ReverseNumber(ReadPositiveNumber("Enter Positive Number: "));

    return 0;
}