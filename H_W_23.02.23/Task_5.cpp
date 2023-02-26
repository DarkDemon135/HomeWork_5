#include <iostream>
#include <time.h>
#include <iomanip>
 
using namespace std;
 
void convertArray(int* startArray, int arraySize);
void printArray(int* arr, int size);
 
int main()
{
    srand((int)time(NULL));
    int const arraySize = 50;
    int startArray[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        startArray[i] = rand() % 20 - 10;
    }
    cout << "Начальный массив: " << endl;
    printArray(startArray, arraySize);
    convertArray(startArray, arraySize);
}
 
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << setw(3) << *(arr + i);
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}
 
void convertArray(int* startArray, int arraySize)
{
    int positiveArraySize = 0;
    int negativeArraySize = 0;
    int zeroArraySize = 0;
 
    for (int i = 0; i < arraySize; i++)
    {
        if (startArray[i] > 0)
        {
            positiveArraySize++;
        }
        else if (startArray[i] < 0)
        {
            negativeArraySize++;
        }
        else
        {
            zeroArraySize++;
        }
    }
    if ((positiveArraySize + negativeArraySize + zeroArraySize) != arraySize)
    {
        cout << "Ошибка" << endl;
    }
    int* positiveElementsArray = new int[positiveArraySize];
    int* negativeElementsArray = new int[negativeArraySize];
    int* zeroElementsArray = new int[zeroArraySize];
    int positiveIterator = 0;
    int negativeIterator = 0;
    int zeroIterator = 0;
 
    for (int i = 0; i < arraySize; i++)
    {
        if (startArray[i] > 0)
        {
            positiveElementsArray[positiveIterator] = startArray[i];
            positiveIterator++;
        }
        else if (startArray[i] < 0)
        {
            negativeElementsArray[negativeIterator] = startArray[i];
            negativeIterator++;
        }
        else
        {
            zeroElementsArray[zeroIterator] = startArray[i];
            zeroIterator++;
        }
    }
    cout << "Массив положительных элементов: " << endl;
    printArray(positiveElementsArray, positiveArraySize);
    cout << "Массив отрицательных элементов: " << endl;
    printArray(negativeElementsArray, negativeArraySize);
    cout << "Массив нулевых элементов: " << endl;
    printArray(zeroElementsArray, zeroArraySize);
 
    delete[] positiveElementsArray;
    delete[] negativeElementsArray;
    delete[] zeroElementsArray;
}