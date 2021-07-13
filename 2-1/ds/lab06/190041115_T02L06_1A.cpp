#include <bits/stdc++.h>
#include "AVL.cpp"
using namespace std;


int main() {
    AVL a;
    int x;
    while(cin >> x && x != -1) {
        AVL::Node *i = a.insert(x);
        a.inOrder(a.Root);
        cout << "\n";
        AVL::Node *n = a.getImbalanced(i);
        if(n == NULL) cout << "Balanced!\n";
        else {
            cout << "Imbalance at node: " << n->data << "\n";
            // LL case
            // left_rotate(12)
            // inOrder(a.Root);
        }
        cout << "Root = " << a.Root->data << "\n";
        
        cout << "----------------------\n";
    }

}
