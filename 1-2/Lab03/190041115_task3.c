#include <stdio.h>

#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)

#define inf 1e9+5

int arr[100010];
int n;

int first(int x) {
	int l = 0, r = n-1;
	int res = inf;
	while(l <= r) {
		int mid = l+(r-l)/2;
		if(arr[mid] == x) {
			res = min(res, mid);
			r = mid-1;
		} 
		else if(arr[mid] > x) r = mid-1;
		else l = mid+1;
	}
	if(res == inf) return -1;
	return res;
}

int last(int x) {
	int l = 0, r = n-1;
	int res = -inf;
	while(l <= r) {
		int mid = l+(r-l)/2;
		if(arr[mid] == x) {
			res = max(res, mid);
			l = mid+1;
		}
		else if(arr[mid] > x) r = mid-1;
		else l = mid+1;
	}
	if(res == -inf) return -1;
	return res;
}

int main() {
	int k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("First occurance of element %d is at position: %d\n", k, first(k));
	printf("Last occurance of element %d is at position: %d\n", k, last(k));
	return 0;
}
