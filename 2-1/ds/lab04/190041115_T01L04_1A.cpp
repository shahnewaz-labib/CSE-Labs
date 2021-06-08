#include <iostream>
#define HEAD_KEY 90909090
#define log(x) cout<<x<<"\n";
using namespace std;

class Node {
    public:
        int key;
        Node* next;
};

void insert_back(int key, Node *head) {
    Node *temp = new Node();
    temp->key = key;
    temp->next = NULL;
    while(head->next != NULL) {
        head = head->next;
    }
    head->next = temp;
    return;
}

void insert_front(int key, Node *head) {
    Node *temp = new Node();
    temp->key = key;
    temp->next = head->next;
    head->next = temp;
    return;
}

void show(Node *head) {
    //if(head->key == HEAD_KEY) head = head->next; 
    head = head->next; 
    while(head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << "\n";

}

void insert_after_node(int key, int v, Node *head) {
    while(head != NULL) {
        if(head->key == v) break;
        head = head->next;
    }
    if(head == NULL) {
        log("No such node!");
        return;
    }
    Node *temp = new Node();
    temp->key = key;
    temp->next = head->next;
    
    head->next = temp;

    return;

}

void update_node(int key, int v, Node *head) {
    head = head->next;
    while(head != NULL) {
        if(head->key == v) break;
        head = head->next;
    }
    if(head == NULL) {
        log("No such node!");
        return;
    }
    head->key = key;

    return;


}

void remove_node(int key, Node *head) {
    while(head != NULL) {
        if(head->next != NULL) {
            if(head->next->key == key) break;
        }
        head = head->next;
    }
    if(head == NULL) {
        log("No such node!");
    }
    Node *temp = head;
    head->next = head->next->next;
    free(head);
}

void remove_end(Node *head) {
    if(head->next == NULL) return;
    while(head->next->next != NULL) {
        head = head->next;
    }
    free(head->next);
    head->next = NULL;
}



int main() {
    Node *Head = new Node();
    Head->key = HEAD_KEY;
    Head->next = NULL;

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
            insert_front(key, Head);
        } else if(choice == 2) {
            cin >> key;
            insert_back(key, Head);
        } else if(choice == 3) {
            cin >> key >> v;
            insert_after_node(key, v, Head);
        } else if(choice == 4) {
            cin >> key >> v;
            update_node(key, v, Head);
        } else if(choice == 5) {
            cin >> key;
            remove_node(key, Head);
        } else if(choice == 6) {
            remove_end(Head);
        } else if(choice == 7) {
            break;
        }


        show(Head);


    }



}
