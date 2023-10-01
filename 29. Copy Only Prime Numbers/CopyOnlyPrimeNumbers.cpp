#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

enum enPrime {NotPrime, Prime};

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

enPrime CheckPrime(int Number)
{
    int HalfNumber = round(Number / 2);

    for (int Counter = 2; Counter <= HalfNumber; Counter++)
    {
        if (Number % Counter == 0)
            return enPrime::NotPrime;
    }

    return enPrime::Prime;
}

void CopyArrayPrimeNumbers(int SourceArray[100], int DestinatonArray[100], int ArrayLength, int &Array2Length)
{
    int Counter = 0;
    for (int i = 0; i < ArrayLength; i++)
    {
        if (CheckPrime(SourceArray[i]) == enPrime::Prime)
        {
            DestinatonArray[Counter] = SourceArray[i];
            Counter++;
            Array2Length++;
        }
    } 
}


int main()
{
    srand(unsigned(time(NULL)));

    int Array1[100], Array2[100], ArrayLength, Array2Length = 0;

    FillArrayWithRandomNumbers(Array1, ArrayLength);
    
    cout << "Array1 Elemets: ";
    PrintArray(Array1, ArrayLength);

    CopyArrayPrimeNumbers(Array1, Array2, ArrayLength, Array2Length);
    cout << "Prime Numbers in Array2: ";
    PrintArray(Array2, Array2Length);

    return 0;
}