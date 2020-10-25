#include <stdio.h>
#include <stdbool.h>

int n, m, sx, sy, nc, source_color;
int grid[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
    if(!valid(x, y) || grid[x][y] != source_color) return;
    grid[x][y] = nc;
    for(int i = 0; i < 4; i++)
        dfs(x+dx[i], y+dy[i]);
}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &sx, &sy, &nc);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &grid[i][j]);
    source_color = grid[sx][sy];
    dfs(sx, sy);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
    return 0;
}
