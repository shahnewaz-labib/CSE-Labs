#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

struct Students {
    string name;
    int total, ml, ds, net;
};

bool cmp(Students a, Students b) {
    if(a.total != b.total) return a.total > b.total;
    if(a.ml != b.ml) return a.ml > b.ml;
    if(a.ds != b.ds) return a.ds > b.ds;
    return false;
}

int main() {
    int n; cin >> n;
    Students student[n];
    for(int i = 0; i < n; i++) {
        cin >> student[i].name >> student[i].ml >> student[i].ds >> student[i].net;
        student[i].total = student[i].ml + student[i].ds + student[i].net;
    }

    sort(student, student+n, cmp);

    for(int i = 0; i < n; i++) {
        cout << i+1 << " " << student[i].name << '\n';
    }
    
}