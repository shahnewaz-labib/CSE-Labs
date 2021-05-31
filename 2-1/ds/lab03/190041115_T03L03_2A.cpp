#include <iostream>
#define d(x) cout << #x << " = " << x << "\n";
#define ERROR 9999999;
using namespace std;
const int mx = 1e6;


class Min_Heap {
private:
    int arr[mx];
    int size;
public:
    Min_Heap() {
        size = 0;
    }
    void heapify(int i, int n) {
        int l = 2*i+1, r = l+1, mx = i;
        if(l < n && -arr[l] > -arr[mx]) mx = l;
        if(r < n && -arr[r] > -arr[mx]) mx = r;
        if(mx != i) {
            swap(arr[mx], arr[i]);
            heapify(mx, n);
        }
    }
    void create(int n) {
        for(int i=n/2-1; i>=0; i--) {
            heapify(i, n);
        }
    }
    void take_input(int n) {
        for(int i=0;i<n;i++) cin >> arr[i];
        size = n;
    }
    void show() {
        for(int i=0;i<size;i++) cout << arr[i] << " ";
        cout << "\n";
    }
    int minimum() {
        return arr[0];
    }
    int extract_min() {
        if(size == 0) return ERROR;
        int x = arr[0];
        swap(arr[0], arr[size-1]);
        heapify(0, --size);
        return x;
    }
    int Size() {
        return size;
    }
    bool empty() {
        return size == 0;
    }
    void insert(int x) {
        if(size == mx) return;
        size++;
        arr[size-1] = x;
        int i = size-1;
        while(i > 0 && arr[i] < arr[(i-1)/2]) {
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void decrese_key(int pos, int value) {
        if(pos >= size) return;
        arr[pos] = value;
        while(pos > 0 && arr[pos] < arr[(pos-1)/2]) {
            swap(arr[pos], arr[(pos-1)/2]);
            pos = (pos-1)/2;
        }
    }

    void increase_key(int pos, int value) {
        if(pos >= size) return;
        arr[pos] = value;
        heapify(pos, size);
    }

};




int main() {
    int n; cin >> n;
    Min_Heap h;
    h.take_input(n);
    h.create(n);
    
    h.show();
    
    h.show();




    return 0;
}

