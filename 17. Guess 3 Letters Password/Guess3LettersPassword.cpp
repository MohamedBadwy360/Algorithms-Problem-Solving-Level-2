#include <iostream>

using namespace std;

string ReadPasswordLetters()
{
    string Password = "";

    do
    {
        cout << "Enter 3 Letters Password: ";
        cin >> Password;
    }
    while (Password.length() != 3);

    return Password;
}

void CheckPassword(string Password)
{
    string Word = "";
    int Counter = 0;
    
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                Counter++;

                Word = Word + char(i);
                Word = Word + char(j);
                Word = Word + char(k);

                cout << "Trial [" << Counter << "]: " << Word << endl;

                if (Word == Password)
                {
                    cout << "Password is: " << Password << endl;
                    cout << "Found After " << Counter << " Trials.\n";

                    return;
                }

                Word = "";
            }
        }
    }
}

int main()
{
    CheckPassword(ReadPasswordLetters());

    return 0;
}