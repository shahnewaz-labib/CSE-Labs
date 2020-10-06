#include <stdio.h>
#include <stdbool.h>

int arr[1001][1001];
int n, m, x;
int row(int x) {
	int l = 0, r = n-1;
	while(l <= r) {
		int mid = l+(r-l)/2;
		if(arr[mid][m-1] < x) l = mid+1;
		else r = mid-1;
	}
	return l;
}

int solve(int x) {
	int ro = row(x);
	int l = 0, r = m-1;
	while(l <= r) {
		int mid = l+(r-l)/2;
		if(arr[ro][mid] == x) return true;
		else if(arr[ro][mid] > x) r = mid-1;
		else l = mid+1;
	}
	return false;
}

int main() {
	scanf("%d %d %d", &n, &m, &x);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	// printf("%s\n", bs() ? "True" : "False");
	printf(solve(x) ? "True\n" : "False\n");
	return 0;
}
