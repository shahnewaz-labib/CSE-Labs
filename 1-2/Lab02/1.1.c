#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    for(int i = 0; i < n; i++) printf("%d ", arr[i]); printf("\n");
    return;
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < n-1; i++) {
        if(arr[i+1] < arr[i]) {
            printf("NO\n");
            bubbleSort(arr, n);
            return 0;
        }
    }
    printf("YES\n");
    return 0;

    
    return 0;
}