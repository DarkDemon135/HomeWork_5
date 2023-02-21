#include <iostream>

using namespace std;

int main()
{
    double n, m, summ, sarif;
    int SIZE;
    cin >> SIZE;
    const int R_MIN = -85;
    const int R_MAX = 85;
    int arr[SIZE][SIZE];
    int i, j;
 
    srand(time(NULL));
 
    for(i = 0; i < SIZE; ++i)
    {
        for(j = 0; j < SIZE; ++j)
        {
            arr[i][j] = rand()%(R_MAX-R_MIN+1) + R_MIN;
            // или тупо: arr[i][j] = rand()%101-50;
        }
    }
 
    for(i = 0; i < SIZE; ++i)
    {
        for(j = 0; j < SIZE; ++j)
        {
            cout<<arr[i][j]<<'\t';
        }
        cout<<endl;
    }

    for(int i = 0; i < m; i++) {     
     summ += arr[i][0];           
     sarif = summ / SIZE;   
    }      
    
    cout << '\n';     
    cout << "Srednee arifmiticheskoe = " << sarif;
 
    cout<<endl;
    return 0;
}