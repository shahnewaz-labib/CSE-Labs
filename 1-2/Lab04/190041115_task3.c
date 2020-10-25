#include <stdio.h>
#include <string.h>
#define ll long long

ll dp[38];

ll fib(int n) {
    if(dp[n] != -1) return dp[n];
    ll result;
    if(n == 0) result = 0;
    if(n == 1 || n == 2) result = 1;
    else result = fib(n-1)+fib(n-2)+fib(n-3);
    dp[n] = result;
    return dp[n];
}

int main() {
    memset(dp, -1, sizeof dp);
    int n; scanf("%d", &n);
    printf("%lld\n", fib(n));
    return 0;
}
