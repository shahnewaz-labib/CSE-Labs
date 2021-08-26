#include "bits/stdc++.h"
using namespace std;

class People {
private:
    string *name;
public:
    People() {
        name = new string;
        *name = "";
    }
    void setName(string n) {
        *name = n;
    }
    string getName() {
        return *name;
    }
};

class people {
private:
    string *name;
public:
    people() {
        name = new string;
        *name = "";
    }
    people(people &p) {
        name = new string;
        *name = *p.name;
    }

    void operator=(people &p) {
        name = new string;
        *name = *p.name;
    }

    void setName(string n) {
        *name = n;
    }

    string getName() {
        return *name;
    }


};

class A {
private:
    int a;
    A(A &a) {
        // copy
    }
    void operator=(A &x) {
        a = x.a;
    }
public:
    A() {
        a = 0;
    }

};

int main() {
    People P1;
    P1.setName("ABCD");

    People P2 = P1;
    P1.setName("ZZZZ");


    cout << P1.getName() << "\n";
    cout << P2.getName() << "\n";

    cout << "-----------------\n\n";

    people p1;
    p1.setName("xyz");

    people p2 = p1;
    p1.setName("abcd");
    
    cout << p1.getName() << "\n";
    cout << p2.getName() << "\n";

/*
    A a;
    A b = a, c;
    c = a;
*/

    return 0;
}
