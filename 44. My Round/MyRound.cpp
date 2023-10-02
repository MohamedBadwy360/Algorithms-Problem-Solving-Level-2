#include <iostream>
#include <cmath>

using namespace std;

int MyRound(float Number)
{
    int Remainder = int(Number * 10) % 10;

    if (Number > 0)
    {
        if (Remainder >= 5)
            return int(Number) + 1;
        else 
            return int(Number);
    }
    else 
    {
        if (Remainder <= -5)
            return int(Number) - 1;
        else 
            return int(Number);
    }
        
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