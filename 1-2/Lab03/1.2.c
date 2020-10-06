#include <stdio.h>
#include <stdbool.h>

int arr[1001][1001];

bool bs() {

}

int main() {
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	printf("%s\n", bs() ? "True" : "False");
	return 0;
}
