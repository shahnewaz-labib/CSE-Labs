#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}


int main() {
    int m;
    scanf("%d", &m);
    int arr[m], index[m];
    for(int i = 0; i < m; i++) scanf("%d", &arr[i]), index[i] = i;
    for(int i = 0; i < m; i++)
        for(int j = i+1; j < m; j++)
            if(arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
                swap(&index[i], &index[j]);
            }
    for(int i = 0; i < m; i++) printf("%d ", index[i]);
    printf("\n");
    return 0;
}