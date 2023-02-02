#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

template<class T>
void sort_arr(T* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
int64_t binarySearch(T arr[], int64_t nSize, T value)
{
    if(arr[0]==value) return 0;
    if(arr[nSize-1]==value) return nSize-1;
    int64_t l=0;
    int64_t r=nSize-1;
    int64_t m;
    while(true)
    {
        m=(l+r)/2;
        if(m==l) return -1;
        if(arr[m]==value) return m;
        if(arr[m]<=value) l=m;
        else r=m;
    }
    return -1;
}
int main()
{
    int arr[] = { 4, 2, 1, 3, 0, 5 };
 
    int min = INT_MAX, max = INT_MIN;
    for (int i: arr)
    {
        if (i < min) {
            min = i;
        }
 
        if (i > max) {
            max = i;
        }
    }
 
    std::cout << "The min element is " << min << std::endl;
    std::cout << "The max element is " << max << std::endl;
 
    int size = 6;
 
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
 
    sort_arr<int>(arr, size);
 
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
 
    return 0;
}