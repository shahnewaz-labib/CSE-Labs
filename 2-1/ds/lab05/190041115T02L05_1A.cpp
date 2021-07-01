#include <iostream>
#include <queue>
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

    void insert(int x) {
        // no nodes in BST
        if(Root == NULL) {
            Root = new Node(x);
            // cout << "Inserted at root\n";
            return;
        }

        Node *head = Root;
        Node *temp = new Node(x);

        while(true) {
            // cout << "visiting " << head->value << "\n";
            if(x <= head->value) {
                if(head->left == NULL) {
                    head->left = new Node(x);
                    break;
                } else {
                    head = head->left;
                }
            } else {
                if(head->right == NULL) {
                    head->right = new Node(x);
                    break;
                } else {
                    head = head->right;
                }
            }
        }

        return;
    }


    void LevelOrder() {
        queue<Node*> q;
        q.push(Root);
        Node cur;
        while(!q.empty()) {
            cur = *q.front();
            q.pop();
            cout << cur.value << "\n";
            if(cur.left != NULL)
                q.push(cur.left);
            if(cur.right != NULL)
                q.push(cur.right);
        }
    }

};

int main() {
    BST b;
    int x=0;
    while(cin >> x and x != -1) {
        b.insert(x);
    }
    b.LevelOrder();
}
