#include "bits/stdc++.h"
using namespace std;

const int mx = 1e5+10;
struct Node {
    int prop = 0, sum = 0;
} tree[mx*3];
int arr[mx];

void init(int node, int b, int e) {
    if(b == e) {
        tree[node].sum = arr[b];
        return;
    }
    int left = node*2, right = left+1, mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    
    tree[node].sum = tree[left].sum + tree[right].sum;

}

void update(int node, int b, int e, int i, int j, int x) {
    if(e < i || j < b) return;
    if(i <= b && e <= j) {
        tree[node].prop += x;
        tree[node].sum += (e-b+1)*x;
        return;
    }
    int left = node << 1, right = left+1, mid = (b+e) >> 1;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);

    tree[node].sum = tree[left].sum + tree[right].sum + tree[node].prop * (e-b+1);

}


int main() {
    


    return 0;
}
