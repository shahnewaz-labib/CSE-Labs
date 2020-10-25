#include <stdio.h>

void func(int num, int n) {
    if(num > n) return;
    printf("%d ", num);
    func(num+2, n);
}

int main() {
    int n; scanf("%d", &n);
    func(0, n);
    printf("\n");
    return 0;
}
