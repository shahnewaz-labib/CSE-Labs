#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[]) {
	srand(atoi(argv[1]));
	int n = rand(2, 50);
	int k = rand(1, 100);
	printf("%d %d\n", n, k);
	int arr[n];
	for(int i = 0; i < n; i++) {
		int x;
		x = rand(1, 100);
		// printf("%d ", x);
		arr[i] = x;
	}
	sort(arr, arr+n);
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
