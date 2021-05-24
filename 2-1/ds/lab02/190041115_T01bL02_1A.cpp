#include <iostream>
#include <stack>

using namespace std;


int main() {
    stack<int> st, temp;
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
        
        temp = st;
        if(temp.empty()) {
            cout << "NULL\n";
            continue;
        }
        else {
            while(!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << "\n";
        }

    }

    return 0;
}
