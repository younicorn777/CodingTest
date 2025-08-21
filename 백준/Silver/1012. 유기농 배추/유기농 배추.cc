#include <bits/stdc++.h>
using namespace std;
const int max_n = 52;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int t, n, m, k, cy, cx, a[max_n][max_n], visited[max_n][max_n];

void DFS(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (a[ny][nx] && !visited[ny][nx]) DFS(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		int cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> cx >> cy;
			a[cy][cx] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] && !visited[i][j]) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
	}
}