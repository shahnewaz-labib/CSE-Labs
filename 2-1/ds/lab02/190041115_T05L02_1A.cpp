#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int s = 1;
    stack<int> st;
    for(int i=0;i<n;i++){
        cin >> x;
        if(x == s) {
            s++;
        } else if(!st.empty() and st.top() == x) {
            s++;
            st.pop();
        } else {
            st.push(x);
        }
    }
    if(s == n+1) {
        cout << "Yes\n";
        return 0;
    }
    while(!st.empty()) {
        if(s == st.top()) {
            s++;
            st.pop();
        } else {
            cout << "No\n";
            st.pop();
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
