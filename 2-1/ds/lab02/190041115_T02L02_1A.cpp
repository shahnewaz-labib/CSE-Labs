#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    stack<char> st;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        for(char c : s) st.push(c);
        while(!st.empty()) {
            cout << st.top();
            st.pop();
        }
        cout << "\n";
    }
}
