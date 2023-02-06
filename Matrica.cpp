#include<iostream>
using namespace std;
 
int main()
{
    srand(time(NULL));
    int N, M;
    int sum=0;
    int mass[N], max, min;
    cout<<"Введите размер массива: ";
    cin >> N >> M;
    int ** A = new int * [N];
    for (int i = 0; i < N; i++)
        A [i] = new int [M];
 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            A [i][j] = ((rand() % 10));
                        
        
 cout << "Вот ваш массив:" << endl << endl;
 for (int i = 0; i < N; i++)
 {
     for(int j = 0; j < M; j++){
         cout << A[i][j] << " ";
     }
     cout << endl;
 }
   max = mass[0];
	min = mass[0];
	for (int i = 0; i < N; i++)
 {
     for(int j = 0; j < M; j++){
		if(max < A[i][j]) max = A[i][j];
		if(min > A[i][j]) min = A[i][j];
	}
 }
	cout << "\nMin: " << min << endl;
	cout << "Max: " << max << endl;

    cout << endl;

    for (int i = 0; i < N; i++)
       delete [] A[i];
    delete [] A;
    return 0;
}