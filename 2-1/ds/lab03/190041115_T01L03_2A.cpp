#include <bits/stdc++.h>
#define d(x) cout << #x << " = " << x << "\n"
#define ERROR INT_MAX
using namespace std;

const int mx = 1e6;

class Linear_Queue {
private:
    int arr[mx];
    int Size;
    int top, front;
public:
    Linear_Queue() {
        front = Size = 0;
        top = -1;
    }
    int size() {
        return Size;
    }
    void push(int x) {
        arr[++top] = x;
        Size++;
    }
    int pop() {
        if(front > top) return ERROR;
        return arr[front++];
    }
    bool empty() {
        return Size == 0;
    }
    void show() {
        for(int i=0;i<Size;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
};

class Circular_Queue {
private:
    int arr[mx], back, front, Size;
public:
    Circular_Queue() {
        back = -1;
        Size = front = 0;
    }
    void push(int x) {
        back = (back+1)%mx;
        Size++;
        arr[back] = x;
    }
    void pop() {
        int temp = arr[front];
        front = (front+1)%mx;
        Size--;
    }
    int top() {
        return arr[front];
    }
    int size() {
        return Size;
    }
    bool empty() {
        return Size == 0;
    }
};

int main() {
    Circular_Queue q;
    for(int i=10;~i;i--) q.push(i);
    while(q.size()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << "\n";


    return 0;
}

