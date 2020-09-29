#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    // int arr[n];
    int x;
    int teams = 0;
    for(int i = 0; i < n; i++) {
        // scanf("%d", &arr[i]);
        scanf("%d", &x);
        if(x <= 5-k) teams++;
    }
    printf("%d\n", teams/3);
}