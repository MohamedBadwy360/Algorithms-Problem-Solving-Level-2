#include <iostream>
#include <cstdlib>

using namespace std;

enum enCharType {SmallLetters, CapitalLetters, SpecialCharacter, Digits};

int RandomNumber(int From, int To)
{
    return (rand() % (To - From + 1) + From);
}

void GetRandomCharacters(enCharType Letters)
{
    switch (Letters)
    {
        case enCharType::CapitalLetters:
            cout << char(RandomNumber(65, 90)) << endl;
            break;
        case enCharType::SmallLetters:
            cout << char(RandomNumber(97, 122)) << endl;
            break;
        case enCharType::SpecialCharacter:
            cout << char(RandomNumber(32, 47)) << endl;
            break;
        case enCharType::Digits:
            cout << RandomNumber(0, 9) << endl;
            break;
    }
}

int main()
{
    srand(unsigned(time(NULL)));

    GetRandomCharacters(enCharType::CapitalLetters);
    GetRandomCharacters(enCharType::SmallLetters);
    GetRandomCharacters(enCharType::SpecialCharacter);
    GetRandomCharacters(enCharType::Digits);

    return 0;
}