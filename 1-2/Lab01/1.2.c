#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", n ? (int)log10(n)+1 : 1);
    return 0;
}
