#include <stdio.h>
/*
0
01
0110
01101001
*/
int solve(int n, int k) {
	if(n == 1) return 0;
	int ans = solve(n-1, (k+1)/2);
	if(ans == 1) return k&1;
	return !(k&1);
}

int main(void) {
	int n, k; scanf("%d %d", &n, &k);
	printf("%d\n", solve(n, k));
	return 0;
}
