#include <bits/stdc++.h>
using namespace std;

class AVL {
    /*
    class Node {
    public:
        int height, data;
        Node *left, *right, *parent;
        
        Node() {
            left = right = parent = NULL;
        }

        Node(int d, Node *l, Node *r, Node *p) {
            height = 0;
            data = d;
            left = l, right = r, parent = p;
        }

    };
    */
public:
    class Node {
    public:
        int height, data;
        Node *left, *right, *parent;
        
        Node() {
            left = right = parent = NULL;
        }

        Node(int d, Node *l, Node *r, Node *p) {
            height = 0;
            data = d;
            left = l, right = r, parent = p;
        }

    };


    Node *Root;
    AVL() {
        Root = NULL;
    }

    void insert(int key) {
        if(Root == NULL) {
            Root = new Node(key, NULL, NULL, NULL);
            return;
        }

        Node *cur = Root;
        Node *prev = Root;
        while(cur != NULL) {
            prev = cur;
            if(key > cur->data) cur = cur->right;
            else if(key <= cur->data) cur = cur->left;
        }

        cur = new Node(key, NULL, NULL, prev);
        if(key <= prev->data) prev->left = cur, cur->parent = prev;
        else prev->right = cur, cur->parent = prev;
        updateHeight(cur);
    }


    void updateHeight(Node *x) {
        while(x != Root) {
            x = x->parent;
            x->height = 1 + max(height(x->left), height(x->right));
        }
    }


    int height(Node *x) {
        if(x) return x->height;
        return -1;
    }


    int balanceFactor(Node *x) {
        return height(x->left) - height(x->right);
    }


    Node *getImbalanced(Node *x) {
        while(x != Root) {
            x = x->parent;
            if(abs(balanceFactor(x)) > 1) {
                return x;
            }
        }
        return NULL;
    }
    
    void leftRotate(Node *x);
    void rightRotate(Node *x);
    void checkBalance(Node *x);


    void inOrder(Node *x) {
        if(x == NULL) return;
        inOrder(x->left);
        cout << x->data << "(" << balanceFactor(x) << ") ";
        inOrder(x->right);
    }

};

