#include <bits/stdc++.h>
#define HEAD_KEY 999999
#define TAIL_KEY 111111
using namespace std;

class Node {
public:
    int key;
    Node *next, *prev;
};

class Dequeue {
private:
    Node *Head, *Tail;
public:
    Dequeue() {
        Head = new Node();
        Tail = new Node();

        Head->next = Tail;
        Head->prev = NULL;
        Head->key = HEAD_KEY;

        Tail->next = NULL;
        Tail->prev = Head;
        Tail->key = TAIL_KEY;
    }
    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    void show();
    void rshow();
};

void Dequeue::push_front(int x) {
    Node *temp = new Node();
    temp->key = x;
    temp->next = Head->next;
    temp->prev = Head;
    Head->next->prev = temp;
    Head->next = temp;
    return;
}

void Dequeue::push_back(int x) {
    Node *temp = new Node();
    temp->key = x;
    temp->prev = Tail->prev;
    temp->next = Tail;

    Tail->prev->next = temp;
    Tail->prev = temp;
    return;
}

int Dequeue::pop_front() {
    Node *temp = Head->next;
    if(temp == Tail) return -1;
    int key = temp->key;
    Head->next = temp->next;
    temp->next->prev = Head;
    free(temp);
    return key;
}

int Dequeue::pop_back() {
    Node *temp = Tail->prev;
    if(temp == Head) return -1;
    int key = temp->key;
    temp->prev->next = Tail;
    Tail->prev = temp->prev;
    free(temp);

    return key;
}

void Dequeue::show() {
    Node *head = Head;
    head = head->next;
    if(head == Tail) {
        cout << "Dequeue empty\n";
    }
    while(head != Tail) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << "\n";
    return;
}

void Dequeue::rshow() {
    Node *head = Tail;
    head = head->prev;
    if(head == Tail) {
        cout << "Dequeue empty\n";
    }
    while(head != Head) {
        cout << head->key << " ";
        head = head->prev;
    }
    cout << "\n";
    return;
}

int main() {
    int choice = 0, x;
    Dequeue d;
    while(choice != 5) {
        cout << "Press:\n1 to push_front\n2 to push_back\n3 to pop_front\n4 to pop_back\n5 to exit";
        cin >> choice;
        if(choice == 1) {
            cin >> x;
            d.push_front(x);
        } else if(choice == 2) {
            cin >> x;
            d.push_back(x);
        } else if(choice == 3) {
            d.pop_front();
        } else if(choice == 4) {
            d.pop_back();
        } else if(choice == 5) {
            break;
        }


        d.show();

    }
}
