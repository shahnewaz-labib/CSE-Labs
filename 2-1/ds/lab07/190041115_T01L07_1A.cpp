#include "bits/stdc++.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
using namespace std;
const int mx = 1e5+10;


int arr[mx], tree[3*mx];
void init(int node, int b, int e) {
    if(b == e) {
        tree[node] = arr[b];
        return;
    }
    int left = 2*node, right = left+1, mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);

    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j) {
    if(e < i || j < b) return mx;
    if(i <= b && e <= j) return tree[node];

    int left = 2*node, right = left+1, mid = (b+e)/2;
    int q1 = query(left, b, mid, i, j);
    int q2 = query(right, mid+1, e, i, j);

    return min(q1, q2);
}

int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1, 1, n);
    int a, b;
    while(q--) {
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << "\n";
    }
    return 0;
}
