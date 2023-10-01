#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    return (rand() % (To - From + 1) + From);
}

void FillArrayWithRandomNumbers(int Array[100], int &ArrayLength)
{
    cout << "Enter Array Length: ";
    cin >> ArrayLength;

    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = RandomNumber(1, 100);
    }
    
    cout << "----------------------\n";
}

void PrintArray(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }

    cout << "\n----------------------\n";
}

void CopyArrayReversed(int SourceArray[100], int DestinatonArray[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        DestinatonArray[i] = SourceArray[ArrayLength - i - 1];
    } 
}


int main()
{
    srand(unsigned(time(NULL)));

    int Array1[100], Array2[100], ArrayLength;

    FillArrayWithRandomNumbers(Array1, ArrayLength);
    
    cout << "Array1 Elemets: \n";
    PrintArray(Array1, ArrayLength);

    CopyArrayReversed(Array1, Array2, ArrayLength);
    cout << "Array2 Elemets After Copying Array 1 and Reverse it: \n";
    PrintArray(Array2, ArrayLength);

    return 0;
}