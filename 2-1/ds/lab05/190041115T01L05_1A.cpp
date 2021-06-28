#include <iostream>
#include <stack>
using namespace std;

class BST {
    class Node {
    public:
        int value;
        Node *left, *right;
        Node() {

        }
        Node(int _value) {
            value = _value;
            left = right = NULL;
        }
    };
public:
    Node *Root;
    BST() {
        Root = Root->left = Root->right = NULL;
    }

    bool insert(int x) {
        // no nodes in BST
        if(Root == NULL) {
            Root = new Node(x);
            return true;
        }

        Node *head = Root;
        Node *temp = new Node(x);
        //    x
        // 50 53
        while(true) {
            if(x < head->value - 3) {
                if(head->left == NULL) {
                    head->left = new Node(x);
                    return true;
                } else {
                    head = head->left;
                }
            } else if(x > head->value + 3) {
                if(head->right == NULL) {
                    head->right = new Node(x);
                    return true;
                } else {
                    head = head->right;
                }
            } else return false;
        }

    }
        
    void IterativeInOrder() {
        stack<Node*> st;
        Node *cur = Root; 
        while(!st.empty() || cur != NULL) {
            while(cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            cout << st.top()->value << " ";
            cur = st.top()->right;
            st.pop();
            

        }
    
    }
};


int main() {
    BST b;
    int x;
    bool reserved;
    while(cin >> x) {
        if(x == -1) break;
        reserved = !b.insert(x);
        b.IterativeInOrder();
        if(reserved) cout << "(Reservation Failed)";
        cout << "\n";
    }
}
