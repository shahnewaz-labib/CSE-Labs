#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    Node *next, *prev;
};

void insert_at_front(Node *Head, int x) {
    Node *temp = new Node();
    temp->key = x;
    temp->next = Head->next;
    temp->prev = Head;
    Head->next->prev = temp;
    Head->next = temp;
    return;
}

void insert_at_back(Node *Tail, int x) {
    Node *temp = new Node();
    temp->key = x;
    temp->prev = Tail->prev;
    temp->next = Tail;

    Tail->prev->next = temp;
    Tail->prev = temp;
    return;
}

void insert_between(Node *a, Node *b, int x) {
    Node *temp = new Node();
    temp->key = x;
    temp->next = b;
    temp->prev = a;
    a->next = temp;
    b->prev = temp;
}

void insert_after_a_node(Node *head, Node *Tail, int x, int v) {
    Node *temp = new Node();
    temp->key = x;

    while(head != Tail)  {
        if(head->key == v) {
            break;
        }
        head = head->next;
    }

    if(head == Tail) {
        cout << "No such node!\n";
    }

    insert_between(head, head->next, x);

}

void show(Node *head, Node *tail) {
    head = head->next;
    if(head == tail) {
        cout << "Empty!\n";
        return;
    }
    while(head != tail) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << "\n";

}

void update_node(Node *head, Node *Tail, int key, int v) {
    head = head->next;
    while(head != Tail) {
        if(head->key == v) break;
        head = head->next;
    }
    if(head == Tail) {
        cout << "No such node!\n";
        return;
    }
    head->key = key;

    return;


}

void remove_node(Node *head, Node *Tail, int key) {
    while(head != Tail) {
        if(head->next->key == key) break;
        head = head->next;
    }
    if(head == Tail) {
        cout << "No such node!\n";
    }
    Node *temp = head;
    head->next = head->next->next;
    free(temp);
}

void remove_last_node(Node *Tail) {
    Node *b = Tail->prev;
    Node *a = b->prev;
    
    a->next = Tail;
    Tail->prev = a;

    free(b);

}

int main() {
    Node *Head = new Node();
    Node *Tail = new Node();
    Head->next = Tail;
    Tail->prev = Head;

    Head->prev = Tail->next = NULL;

       string s = R"(What do you want to do?
1. Insert at front
2. Insert at back
3. Insert after a node
4. Update a node
5. Remove a node
6. Remove the last node
7. Exit
Enter your choice: )";
 

    int choice = 0, key, v;
    while(choice != 7) {
        cout << s;
        cin >> choice;

        if(choice == 1) {
            cin >> key;
            insert_at_front(Head, key);
        } else if(choice == 2) {
            cin >> key;
            insert_at_back(Tail, key);
        } else if(choice == 3) {
            cin >> key >> v;
            insert_after_a_node(Head, Tail, key, v);
        } else if(choice == 4) {
            cin >> key >> v;
            update_node(Head, Tail, key, v);
        } else if(choice == 5) {
            cin >> key;
            remove_node(Head, Tail, key);
        } else if(choice == 6) {
            remove_last_node(Tail);
        } else if(choice == 7) {
            break;
        }
        show(Head, Tail);

    }

}

/*
Press 1 to insert at front *
Press 2 to insert at back *
Press 3 to insert after a node *
Press 4 to update a node *
Press 5 to remove a node *
Press 6 to remove the last node
Press 7 to exit.


*/
