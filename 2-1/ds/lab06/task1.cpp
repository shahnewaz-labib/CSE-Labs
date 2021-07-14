#include <bits/stdc++.h>
using namespace std;

class BST {
    class Node {
    public:
        int value, child, h;
        Node *left, *right;
        Node() {
            child = 0;
            h = -1;
        }
        Node(int _value) {
            h = -1;
            child = 0;
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

        while(true) {
            if(x < head->value) {
                if(head->left == NULL) {
                    head->left = new Node(x);
                    return true;
                } else {
                    head = head->left;
                }
                head->child++;
            } else if(x > head->value) {
                if(head->right == NULL) {
                    head->right = new Node(x);
                    return true;
                } else {
                    head = head->right;
                }
                head->child++;
            } else return false;
        }

    }


    int height(Node *x) {
        if(x) return max(height(x->left), height(x->right)) + 1;
        return 0;
    }
        
    int balanceFactor(Node *x) {
        return height(x->left) - height(x->right);
    }


    void IterativeInOrder() {
        stack<Node*> st;
        Node *cur = Root; 
        while(!st.empty() || cur != NULL) {
            while(cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            printf("%d(%d) ", st.top()->value, balanceFactor(st.top()));
            cur = st.top()->right;
            st.pop();

        }
    
    }
};



int main() {
    int x;
    BST b;
    while(cin >> x && x != -1) {
        b.insert(x);
        b.IterativeInOrder();
        cout << "\n";
    }

}
