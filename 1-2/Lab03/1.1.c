#include <stdio.h>
#include <stdbool.h>

int arr[10010];
int n, k;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void bubbleSort() {
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(arr[i] > arr[j]) swap(&arr[i], &arr[j]);
		}
	}
	return;
}

bool bs() {
	int l = 0, r = n-1;
	while(l <= r) {
		int mid = l + (r-l)/2;
		if(arr[mid] == k) return true;
		else if(arr[mid] > k) r = mid-1;
		else l = mid+1;
	}
	return false;
}


int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	bubbleSort();
	printf("%s\n", bs() ? "Found" : "Not Found");
	return 0;
}
