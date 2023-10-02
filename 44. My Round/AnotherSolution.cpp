#include <iostream>
#include <cmath>

using namespace std;

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int MyRound(float Number)
{
    int IntegerPart = int(Number);

    if (abs(GetFractionPart(Number)) >= 0.5)
    {
        if (Number > 0)
            return ++IntegerPart;
        else 
            return --IntegerPart;
    }
    else 
        return IntegerPart;
}

float ReadNumber()
{
    float Number; 

    cout << "Please enter a number: ";
    cin >> Number;

    return Number;
}

int main()
{
    float Number = ReadNumber();

    cout << "MyRound = " << MyRound(Number) << endl;
    cout << "C++ Round = " << round(Number) << endl;

    return 0;
}