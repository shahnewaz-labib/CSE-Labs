#include <stdio.h>

#define TC int t; scanf("%d", &t); while(t--)


int main() {
    TC {
        int n, m;
        scanf("%d %d", &n, &m);
        int arr[n];
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(arr[i] > arr[j]) swap(&arr[i], &arr[j]);

        int sum = 0;
        int i = n-1, j = i-(n-m);
        while(i > j) sum += arr[i--];

        i = 0, j = i+(n-m);
        while(i < j) sum -= arr[i++];

        printf("%d\n", sum);
        
    }
}