#include <stdio.h>

int ans[100000];
int n;
void preprocess() {
	ans[1] = 2;
	for(int i = 2; i < 100000; i++) {
		ans[i] = i-1 + i*2 + ans[i-1];
	}
	return;
}

int solve(int x) {
	int l = 0, r = n-1;
	while(l <= r) {
		int mid = l+(r-l)/2;
		if(ans[mid] > x) r = mid-1;
		else l = mid+1;
	}
	return r;
}

int main() {
	preprocess();
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
	return 0;
	
}
