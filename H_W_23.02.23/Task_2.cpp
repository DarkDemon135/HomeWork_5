    #include<iostream>
    #include<time.h>
    #include<stdlib.h>

    using namespace std;
    int main()
    {
        srand(time(NULL));
        int sizeA, sizeB;
        cout << "Введите размер первого массива: " << endl;
        cin >> sizeA;
        cout << "Введите размер второго массива: " << endl;
        cin >> sizeB;
        int *arrA = new int[sizeA];
        int *arrB = new int[sizeB];
        for (int i = 0; i < sizeA; i++)
        {
            arrA[i] = rand() % 10;
            cout << arrA[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < sizeB; i++)
        {
            arrB[i] = rand() % 10;
            cout << arrB[i] << " ";
        }
        cout << endl;
        int tmp = 0;
        for (int i = 0; i < sizeA; i++)
        {
            bool inBoth=false;
            for (int j = 0; j < sizeB; j++)
            {
                if (arrA[i] == arrB[j]){
                    inBoth=true;
                    break;
                }
            }
            if (!inBoth)
                tmp++;
        }
        for (int i = 0; i < sizeB; i++)
        {
            bool inBoth=false;
            for (int j = 0; j < sizeA; j++)
            {
                if (arrB[i] == arrA[j]){
                    inBoth=true;
                    break;
                }
            }
            if (!inBoth)
                tmp++;
        }
        int sizeC = tmp;
        int *arrC = new int[sizeC];
        tmp = 0;
        for (int i = 0; i < sizeA; i++)
        {
            bool inBoth=false;
            for (int j = 0; j < sizeB; j++)
            {
                if (arrA[i] == arrB[j]){
                    inBoth=true;
                    break;
                }
            }
            if (!inBoth)
                arrC[tmp++]=arrA[i];
        }
        for (int i = 0; i < sizeB; i++)
        {
            bool inBoth=false;
            for (int j = 0; j < sizeA; j++)
            {
                if (arrB[i] == arrA[j]){
                    inBoth=true;
                    break;
                }
            }
            if (!inBoth)
                arrC[tmp++]=arrB[i];
        }
        for (int i = 0; i < sizeC; i++)
            cout << arrC[i] << " ";
        cout << endl;
        return 0;
    }