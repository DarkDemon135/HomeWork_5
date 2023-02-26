#include <iostream>
 
using namespace std;
 
int* createArray(int* intArray, int arraySize)
{
    intArray = new int[arraySize];
    return intArray;
}
void initializeArray(int* intArray, int arraySize)
{
    if (intArray == nullptr)
    {
        cout << "Ошибка1" << endl;
        return;
    }
    for (int i = 0; i < arraySize; i++)
    {
        intArray[i] = i + 1;
    }
}
void printArray(int* intArray, int arraySize)
{
    if (intArray == nullptr)
    {
        cout << "Ошибка2" << endl;
        return;
    }
    for (int i = 0; i < arraySize; i++)
    {
        cout << intArray[i] << " ";
    }
    cout << endl;
}
void deleteArray(int* intArray)
{
    delete[] intArray;
}
int* addElementEnd(int* intArrayStart, int* intArrayFinish, int arrayStartSize)
{
    if (intArrayStart == nullptr || intArrayFinish == nullptr )
    {
        cout << "Ошибка3" << endl;
    }
    else
    {
        int userValue;
        int** pIntArrayFinish = &intArrayFinish;
        intArrayFinish = createArray(*pIntArrayFinish, arrayStartSize + 1);
        cout << "Теперь мы добавляем новый элемент в конец массивного" << endl <<
            "Введите новый элемент: ";
        cin >> userValue;
 
        for (int i = 0; i < arrayStartSize; i++)
        {
            intArrayFinish[i] = intArrayStart[i];
        }
        intArrayFinish[arrayStartSize] = userValue;
        cout << "Новый массив: " << endl;
        printArray(intArrayFinish, arrayStartSize + 1);
    }
    return intArrayFinish;
}
int* addElementByIndex(int* intArrayStart, int* intArrayFinish, int arrayStartSize)
{
    if (intArrayStart == nullptr || intArrayFinish == nullptr )
    {
        cout << "Ошибка4" << endl;
    }
    else
    {
        int userIndex;
        int userValue;
        int** pIntArrayFinish = &intArrayFinish;
        intArrayFinish = createArray(*pIntArrayFinish, arrayStartSize + 1);
        cout << "Теперь мы добавляем новый элемент по индексу" << endl <<
            "Введите индекс нового элемента: ";
        cin >> userIndex;
        if (userIndex < 0 || userIndex > arrayStartSize + 1)
        {
            cout << "Ошибка" << endl;
        }
        else
        {
            cout << "Введите новый элемент: ";
            cin >> userValue;
            intArrayFinish[userIndex] = userValue;
            for (int i = 0; i < arrayStartSize; i++)
            {
                if (i >= userIndex)
                {
                    intArrayFinish[i + 1] = intArrayStart[i];
                }
                else
                {
                    intArrayFinish[i] = intArrayStart[i];
                }
            }
            cout << "Новый массив: " << endl;
            printArray(intArrayFinish, arrayStartSize + 1);
        }
    }
    return intArrayFinish;
}
void deleteElement(int* intArray, int arraySize)
{
    if (intArray == nullptr )
    {
        cout << "Ошибка5" << endl;
        return;
    }
    int* newArray = new int[arraySize - 1];
    int userIndex;
    cout << "Теперь мы удаляем один элемент по индексу" << endl <<
        "Введите индекс элемента, который вы хотите удалить: ";
    cin >> userIndex;
    if (userIndex < 0 || userIndex > arraySize)
    {
        cout << "Error" << endl;
    }
    else
    {
        for (int i = 0; i < arraySize; i++)
        {
            if (i > userIndex)
            {
                newArray[i - 1] = intArray[i];
            }
            else
            {
                newArray[i] = intArray[i];
            }
 
        }
        cout << "Новый массив: " << endl;
        printArray(newArray, arraySize - 1);
    }
    delete[] newArray;
}

int main()
{
    int arraySize = 10;
    int* simpleArray1;
    int** pArray1 = &simpleArray1;
    int* simpleArray2;
    int** pArray2 = &simpleArray2;
    int* simpleArray3;
    int** pArray3 = &simpleArray3;
    simpleArray1 = createArray(*pArray1, arraySize);
    initializeArray(simpleArray1, arraySize);
    cout << "Start array: " << endl;
    printArray(simpleArray1, arraySize);
    simpleArray2 = addElementEnd(*pArray1, *pArray2, arraySize);
    simpleArray3 = addElementByIndex(*pArray1, *pArray3, arraySize);
    deleteElement(simpleArray3, arraySize + 1);
    deleteArray(simpleArray1);
    deleteArray(simpleArray2);
    deleteArray(simpleArray3);
}