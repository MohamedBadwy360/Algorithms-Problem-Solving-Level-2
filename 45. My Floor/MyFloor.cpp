#include <iostream>
#include <cmath>

using namespace std;

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int MyFloor(float Number)
{
    if (Number > 0)
        return int(Number);
    else 
        return (int(Number) - 1);
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

    cout << "MyFloor = " << MyFloor(Number) << endl;
    cout << "C++ Floor = " << floor(Number) << endl;

    return 0;
}