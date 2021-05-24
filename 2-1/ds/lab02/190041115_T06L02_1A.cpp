#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, w;
    getline(cin, s);
    stringstream ss(s);
    stack<char> st;
    while(ss >> w) {
        if(w[0] == '(') {
            st.push(w[0]);
        } else {
            if(!st.empty() and st.top() == '(') st.pop();
            else {
                st.push(')');
            }
        }
    }
    cout << st.size() << "\n";
}
