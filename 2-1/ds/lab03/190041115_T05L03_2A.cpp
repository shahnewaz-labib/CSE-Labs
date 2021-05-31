#include <bits/stdc++.h>
using namespace std;

stack<int> rev(stack<int> s) {
    stack<int> temp;
    while(s.size()) {
        temp.push(s.top());
        s.pop();
    }
    return temp;
}

void echo(stack<int> temp) {
    while(temp.size()) {
        cout << temp.top() << " ";
        temp.pop();
    }
}

int main() {
    stack<int> s1, s2;
    int n,t,x;
    cin >> n >> t;
    while(t--) {
        cin>>x;
        cout << "Size:";
        if(x == 1) {
            if(s1.size() == n) {
                cout << n << " elements: Overflow !";
                continue;
            }
            cin >> x;
            s1.push(x);
            stack<int> temp = rev(s1);
            cout << temp.size() << " elements: ";
            echo(temp);
            
        } else {
            s1 = rev(s1);
            s1.pop();
            s1 = rev(s1);
            if(s1.empty()) {
                cout << 0 << " elements: Null";
            } else {
                cout << s1.size() << " elements: ";
                echo(rev(s1));
            }
        }

        cout << "\n";
        
    }
    return 0;
}

