#include <iostream>
#include <queue>
using namespace std;

class BST {
    class Node {
    public:
        int value, lsz;
        Node *left, *right;
        Node() {

        }
        Node(int _value) {
            value = _value;
            left = right = NULL;
            lsz = 0;
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
            if(x < head->value) {
                head->lsz++;
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

    int find(int x) {
        int ans = 0;
        Node *cur = Root;
        while(cur != NULL and cur->value != x) {
            if(x <= cur->value) {
                cur = cur->left;
            } else {
                ans += cur->lsz;
                ans++;
                cur = cur->right;
            }
        }
        if(cur == NULL) return -1;
        ans += cur->lsz;

        return ans;
    }

};

int main() {
    int x, q;
    BST b;
    while(cin >> x and x != -1) b.insert(x);
    cin >> q;
    while(q--) {
        cin >> x;
        cout << b.find(x) << "\n";
    }
}
