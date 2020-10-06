#include <stdio.h>
#include <algorithm>
#include <numeric>
#include <stdbool.h>

using namespace std;
const int MAX = 100000;
int ml[MAX], ds[MAX], net[MAX], total[MAX];

bool cmp(int a, int b) {
    if(total[a] < total[b]) return false;
    if(total[a] == total[b]) {
        if(ml[a] < ml[b]) return false;
        if(ml[a] == ml[b]) {
            if(ds[a] < ds[b]) return false;
            // if(ds[a] == ds[b]) return false;
        }
        return true;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int arr[n]; iota(arr, arr+n, 0);
    char names[n][100];
    for(int i = 0; i < n; i++) {
        scanf("%s %d %d %d", names[i], &ml[i], &ds[i], &net[i]);
        total[i] = ml[i]+ds[i]+net[i];
    }

    sort(arr, arr+n, cmp);

    for(int i = 0; i < n; i++) {
        printf("%d %s\n",i+1, names[arr[i]]);
    }
    
    
}
