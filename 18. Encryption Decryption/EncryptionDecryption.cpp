#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
    string Text;
    
    cout << "Enter Text: \n";
    getline(cin, Text);

    return Text;
}

string EncryptText(string Text, short EncryptionKey)
{
    for (short i = 0; i < Text.length(); i++)
    {
        Text[i] = char(int(Text[i]) + EncryptionKey);
    }

    return Text;
}

string DecryptText(string Text, short EncryptionKey)
{
    for (short i = 0; i < Text.length(); i++)
    {
        Text[i] = char(int(Text[i]) - EncryptionKey);
    }

    return Text;
}

int main()
{
    const short EncryptionKey = 2;

    string Text = ReadText();
    string EncryptedText = EncryptText(Text, EncryptionKey);
    string DecryptedText = DecryptText(EncryptedText, EncryptionKey);

    cout << "Text Before Encryption: " << Text << endl;
    cout << "Text After Encryption : " << EncryptedText << endl;
    cout << "Text After Decryption : " << DecryptedText << endl;


    return 0;
}