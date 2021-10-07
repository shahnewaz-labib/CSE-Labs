#include "bits/stdc++.h"
using namespace std;

struct Node {
    bool end;
    Node *next[26];
    int total;
    Node() {
        end = false;
        total = 0;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
} *Root;

void insert(string &s) {
    Node *cur = Root;
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        if(cur->next[id] == NULL) {
            cur->next[id] = new Node();
        }
        cur = cur->next[id];
        cur->total++;
    }
    cur->end = true;
}

int query(string &s, Node *cur) {
    for(char c : s) {

        if(cur->next[c-'a'] == NULL) {
            break;
        }
        cur = cur->next[c-'a'];
    }
    return cur->total;
}

void convert(string &s) {
    for(char &c : s) {
        c = tolower(c);
    }
}


int main() {
    Root = new Node();

    int n, q;
    string s;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> s;
        convert(s);
        insert(s);
    }
    while(q--) {
        cin >> s;
        convert(s);
        cout << query(s, Root) << "\n";
    }


    return 0;
}
