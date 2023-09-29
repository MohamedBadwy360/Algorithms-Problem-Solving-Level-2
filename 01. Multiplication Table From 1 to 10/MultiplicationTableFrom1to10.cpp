#include <iostream>

using namespace std;

void TableHeader()
{
    cout << "\n\n\t\t\t\tMultiplication Table From 1 to 10\n\n";

    cout << "\t";

    for (int i=1; i<=10; i++)
    {
        cout << "\t" << i;
    }

    cout << "\n-------------------------------------------------------------------------------------------\n";
}

void PrintMultiplicationTable()
{
    TableHeader();

    for (int i=1; i<=10; i++)
    {
        cout << i << "\t|\t";
        for (int j=1; j<=10; j++)
        {
            cout << i * j << "\t";
        }

        cout << endl;
    }
}


int main()
{
    PrintMultiplicationTable();

    return 0;
}