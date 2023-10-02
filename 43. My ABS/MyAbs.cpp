#include <iostream>
#include <cmath>

using namespace std;

int MyAbs(int Number)
{
    if (Number < 0)
        return -Number;
    else 
        return Number;
}

int ReadNumber()
{
    int Number; 

    cout << "Please enter a number: ";
    cin >> Number;

    return Number;
}

int main()
{
    int Number = ReadNumber();

    cout << "MyAbs = " << MyAbs(Number) << endl;
    cout << "C++ Abs = " << abs(Number) << endl;

    return 0;
}