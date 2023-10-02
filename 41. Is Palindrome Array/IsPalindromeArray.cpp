#include <iostream>

using namespace std;

void PrintArray(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }

    cout << "\n----------------------\n";
}

void ReadArray(int Array[100], int &ArrayLength)
{
    cout << "Enter Array Length: ";
    cin >> ArrayLength;
    cout << "----------------------\n";

    cout << "Enter Array Elements: \n";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> Array[i];
    }
    
    cout << "----------------------\n";
}

bool IsPalindromeArray(int Array[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        if (Array[i] != Array[ArrayLength - i - 1])
            return false;          
    }

    return true;
}


int main()
{
    int arr[100], arrLength;

    ReadArray(arr, arrLength);

    cout << "Array Elements: \n"; 
    PrintArray(arr, arrLength);

    if (IsPalindromeArray(arr, arrLength))
        cout << "Yes, Array is palindrome.\n";
    else
        cout << "No, Array isn't palindrome.\n";

    return 0;
}