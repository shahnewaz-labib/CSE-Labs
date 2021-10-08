#include <bits/stdc++.h>
using namespace std;

template <class T>
T amax(T *arr, int size, int n)
{
    T brr[size];
    copy(arr, arr + size, brr);
    sort(brr, brr + size, greater<T>());
    return brr[n - 1];
}

int main()
{

    int arr[10];
    double brr[10];

    for(int i = 0; i < 10; i++) {
        arr[i] = 10-i;
        brr[i] = 10-i+5.5;
    }
    cout << "arr := ";
    for(int i = 0; i < 10; i++) cout << arr[i] << "   ";
    cout << "\nbrr := ";
    for(int i = 0; i < 10; i++) cout << brr[i] << "  ";
    cout << "\n";


    cout << amax(arr, 10, 2) << "\n";
    cout << amax(brr, 10, 2) << "\n";
    
}
