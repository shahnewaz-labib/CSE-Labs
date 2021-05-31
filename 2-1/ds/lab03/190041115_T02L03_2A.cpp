#include <iostream>
using namespace std;

void heapify(int *arr,int i,int len){
    int l = 2*i+1, r = 2*i+2;
    int mx = i;
    if(l < len && arr[l] > arr[mx])
        mx = l;
    if(r<len && arr[r] > arr[mx])
        mx = r;
    if(mx != i){
        swap(arr[i],arr[mx]);
        heapify(arr,mx,len);
    }
}

void heap_sort(int *arr, int n) {
    for(int i=n-1;i>0;i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}


int main(){
    int n; cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    heap_sort(arr, n);
    cout << "\n-------\n";

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

