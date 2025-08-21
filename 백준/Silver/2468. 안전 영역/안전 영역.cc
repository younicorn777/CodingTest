#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n, a[max_n][max_n], visited[max_n][max_n], ret, maxh;
void DFS(int y, int x, int h) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (a[ny][nx] > h && !visited[ny][nx]) DFS(ny, nx, h);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			maxh = max(maxh, a[i][j]);
		}
	}
	for (int i = 0; i < maxh; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (a[j][k] > i && !visited[j][k]) {
					DFS(j, k, i);
					cnt++;
				}
			}
		}
		ret = max(ret, cnt);
		memset(visited, 0, sizeof(visited));
	}
	cout << ret;
}