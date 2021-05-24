#include <bits/stdc++.h>
using namespace std;

int calc(int a, int b, char c) {
    int ans;
    if(c == '+') ans = a+b;
    else if(c == '-') ans = b-a;
    else if(c == '*') ans = a*b;
    else ans = b/a;
    return ans;
}

int main() {
    int t, a, b;
    stack<int> st;
    string s;
    cin >> t;
    while(t--) {
        int ans = 0;
        cin >> s;
        for(char c : s) {
            if(isdigit(c)) {
                st.push(c-'0');
            } else {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(calc(a, b, c));
            }
        }
        cout << st.top() << "\n";

    }
}
