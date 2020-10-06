#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	int f = -1, l = -1;
	for(int i = 0; i < n; i++) {
		if(arr[i] == k) {
			if(f == -1) {
				f = l = i;
			} else {
				l = i;
			}
		}
	}
	printf("%d %d\n", f, l);
	return 0;
}
