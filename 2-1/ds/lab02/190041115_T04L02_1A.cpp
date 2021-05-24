#include<bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    string s;

    while(t--) {
        cin >> s;
        stack<char> st;
        int top;
        bool matched = true;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '[' or s[i] == '{' or s[i] == '(') st.push(s[i]);
            else if(s[i] == ']' or s[i] == '}' or s[i] == ')') {
                if(st.empty()) break;
                else {
                    top = st.top();
                    if((s[i] == (top+1)) or (s[i] == (top+2))) st.pop();
                    else {
                        matched = false;
                        break;
                    }
                }
            }
        }
        if(st.empty() or !matched) cout << "No\n";
        else if(st.empty()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
