#include <iostream>
 
using namespace std;
 
int* selectPrimeNumbers(int* startArray, int arraySize);
 
int main()
{
    int arraySize = 20;
    int* startArray = new int[arraySize];
    int* newArray;
    for (int i = 0; i < arraySize; i++)
    {
        startArray[i] = i + 1;
    }
    cout << "Начальный массив: ";
    for (int i = 0; i < arraySize; i++)
    {
        cout << startArray[i] << " ";
    }
    cout << endl;
    newArray = selectPrimeNumbers(startArray, arraySize);
    delete[] startArray;
    delete[] newArray;
}
 
int* selectPrimeNumbers(int* startArray, int arraySize)
{
    int* bufferArray = new int[arraySize];
    int newSize = 0;
    int divisorsCount = 0;
 
    for (int i = 0; i < arraySize; i++)
    {
        divisorsCount = 0;
        for (int j = 1; j < startArray[i]; j++)
        {
            if (startArray[i] % j == 0)
            {
                divisorsCount++;
            }
        }
 
        if (divisorsCount <= 1)
        {
            bufferArray[newSize] = startArray[i];
            newSize++;
        }
    }
    int* resultArray = new int[newSize];
    cout << "Результат массива: ";
    for (int i = 0; i < newSize; i++)
    {
        resultArray[i] = bufferArray[i];
        cout << resultArray[i] << " ";
    }
    cout << endl;
    delete[] bufferArray;
    return resultArray;
}