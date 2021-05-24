#include <iostream>
using namespace std;

const int MAX = 1e6;

class Stack {
private:
    int top, arr[MAX];
public:
    Stack(){
        top = -1;
    }
    bool isEmpty();
    int size();
    bool push(int x);
    bool pop();
    void show();

};

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::push(int x) {
    if(top == MAX) return false;
    arr[++top] = x;
    return true;
}

bool Stack::pop() {
    if(top == -1) return false;
    top--;
    return true;
}

int Stack::size() {
    if(top == -1) return 0;
    return top+1;
}

void Stack::show() {
    if(top == -1) {
        cout << "NULL\n";
        return;
    } else {
        for(int i=0;i<=top;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    Stack st;
    int mx, t, a, b;
    cin >> mx >> t;
    for(int i=0;i<t;i++) {
        cin >> a;
        if(a == 1) {
            cin >> b;
            st.push(b);
        }
        else {
            st.pop();
        }

        cout << "size=" << st.size() << " items=";
        st.show();

    }

    return 0;
}
