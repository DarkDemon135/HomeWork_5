#include <iostream>

using namespace std;

int main()
{
        srand(time(NULL));
        int sizeA, sizeB;
        cout << "Введите размер первого массива: ";
        cin >> sizeA;
        cout << "Введите размер второго массива: ";
        cin >> sizeB;
        int *arrA = new int[sizeA];
        int *arrB = new int[sizeB];
        cout << "\n\nПервый массив: ";
        for (int x = 0; x < sizeA; x++){
            arrA[x] = rand() % 10;
            cout << arrA[x] << " ";
        }
        cout << "\n\nВторой массив: ";
        for (int x = 0; x < sizeB; x++){
            arrB[x] = rand() % 10;
            cout << arrB[x] << " ";
        }
        int *arrC = new int[sizeA < sizeB ? sizeA : sizeB];
        int sizeC = 0;
        bool flag;
        for (int x = 0; x < sizeA; x++){
            flag = false;
            for (int y = 0; y < sizeB; y++){
                if (arrA[x] == arrB[y]){
                    flag = true;
                    break;
                }
            }
            if (flag == false){
                arrC[sizeC] = arrA[x];
                sizeC++;
            }
        }
        cout << "\n\nТретий массив: ";
        for (int x = 0; x < sizeC; x++)
        {
            cout << arrC[x] << " ";
        }
    return 0;
}
