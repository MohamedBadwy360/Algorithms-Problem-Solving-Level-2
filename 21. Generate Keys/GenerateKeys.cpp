#include <iostream>
#include <cstdlib>

using namespace std;

enum enCharType {SmallLetters, CapitalLetters, SpecialCharacter, Digits};

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

int RandomNumber(int From, int To)
{
    return (rand() % (To - From + 1) + From);
}

char GetRandomCharacters(enCharType CharType)
{
    switch (CharType)
    {
        case enCharType::CapitalLetters:
            return char(RandomNumber(65, 90));
            break;
        case enCharType::SmallLetters:
            return char(RandomNumber(97, 122));
            break;
        case enCharType::SpecialCharacter:
            return char(RandomNumber(32, 47));
            break;
        case enCharType::Digits:
            return char(RandomNumber(48, 57));
            break;
    }
}

string GenerateWord(enCharType CharType, short Length)
{
    string Word = "";

    for (int i = 1; i <= Length; i++)
    {
        Word = Word + GetRandomCharacters(CharType);
    }

    return Word;
}

string GenerateKey()
{
    string Key = "";

    Key = GenerateWord(enCharType::CapitalLetters, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetters, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetters, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetters, 4);

    return Key;
}

void GenerateKeys(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        cout << "Key [" << i << "]: " << GenerateKey() << endl;
    }
}

int main()
{
    srand(unsigned(time(NULL)));
    
    GenerateKeys(ReadPositiveNumber("Enter Positive Number: "));
    return 0;
}