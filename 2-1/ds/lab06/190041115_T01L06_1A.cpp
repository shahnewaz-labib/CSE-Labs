#include <bits/stdc++.h>
#include "AVL.cpp"
using namespace std;

int main() {
    AVL a;
    int x;
    while(cin >> x && x != -1) {
        a.insert(x);
        a.inOrder(a.Root);
        cout << "\n";
    }

}
