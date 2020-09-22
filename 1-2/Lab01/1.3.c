#include <stdio.h>

int freq[1000000];

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;
    }
    int mx = 0, times = 0;
    for(int i = 0; i < 1000000; i++) {
        if(freq[i] > times) {
            times = freq[i];
            mx = i;
        }
    }
    printf("%d", mx);
}
