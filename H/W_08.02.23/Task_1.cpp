#include <iostream>
#include <stdio.h>
#include<string.h>
using namespace std;
 
int main()
{
    int i = 1; //счетчик строк
    int stringLimit = 1000; //ограничени размера считываемой строки
    char* file1Path = "text1.txt";//путь к файлу 1
    char* file2Path = "text2.txt";//путь к файлу 2
    FILE* fileText1 = fopen(file1Path, "rt");
    FILE* fileText2 = fopen(file2Path, "rt");
    if (fileText1 == nullptr || fileText2 == nullptr)
    {
        cout << "Can't open the file" << endl;
        return 1;
    }
 
    char* bufferText1 = new char[stringLimit];
    char* bufferText2 = new char[stringLimit];
 
    //пока не достигнут конец файла
    while (feof(fileText1) == 0)
    {
        fgets(bufferText1, stringLimit, fileText1);
        fgets(bufferText2, stringLimit, fileText2);
        if (strcmp(bufferText1, bufferText2) != 0)
        {
            cout << "STRING #" << i << " / TEXT #1: " << bufferText1;
            cout << "STRING #" << i << " / TEXT #2: " << bufferText2 << endl;
        }
        i++;
    }
    //закрываем файлы
    int closeResult1 = fclose(fileText1);
    int closeResult2 = fclose(fileText2);
    if (closeResult1 == EOF || closeResult2 == EOF)
    {
        fileText1 = nullptr;
        fileText2 = nullptr;
        cout << "Error while closing the file." << endl;
    }
    //удаляем массивы
    delete[] bufferText1;
    delete[] bufferText2;
    return 0;
}