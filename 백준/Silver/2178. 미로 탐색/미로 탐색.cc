#include <bits/stdc++.h>
using namespace std;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int a[104][104], visited[104][104], n ,m, y, x, ny, nx;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) a[i][j] = s[j] - '0';
	}
	
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (a[ny][nx] && !visited[ny][nx]) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}

	cout << visited[n - 1][m - 1];
}