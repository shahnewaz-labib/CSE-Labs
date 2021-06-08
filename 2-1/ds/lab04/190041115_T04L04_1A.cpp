#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    Node *next, *prev;
};

void insert_back(Node *Tail, int key) {
    Node *temp = new Node();
    temp->key = key;
    temp->next = Tail;
    temp->prev = Tail->prev;
    Tail->prev->next = temp;
    Tail->prev = temp;
}

void show(Node *head, Node *Tail) {
    head = head->next;
    if(head == Tail) {
        cout << "Empty!\n";
    }
    while(head != Tail) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << "\n";
}


void join(Node *a, Node *b) {
    a->next = b;
    b->prev = a;
}

void remove_node(Node *a) {
    free(a);
}

int main() {
    Node *Head = new Node(), *Tail = new Node();
    Head->next = Tail;
    Tail->next = NULL;

    Head->prev = NULL;
    Tail->prev = Head;

    int x;
    while(cin >> x) {
        if(x == -1) break;
        insert_back(Tail, x);
    }
    Node *prev = Head->next;
    if(prev == Tail) {
        cout << "No elements to work with!\n";
        return 0;
    }
    Node *cur = prev->next;
    while(cur != Tail) {
        if(cur->key == prev->key) {
            join(prev, cur->next);
            remove_node(cur);
            cur = prev->next;
        } else {
            cur = cur->next;
            prev = prev->next;
        }
    }

    show(Head, Tail);

}
