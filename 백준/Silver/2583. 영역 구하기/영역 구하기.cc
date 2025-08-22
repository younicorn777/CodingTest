#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int a[max_n][max_n], visited[max_n][max_n], m, n, k;
vector<int> v;
void DFS(int y, int x, int& area) {
	visited[y][x] = 1;
	area++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if (!a[ny][nx] && !visited[ny][nx]) DFS(ny, nx, area);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;
		for (int j = m - by; j < m - ay; j++) {
			for (int k = ax; k < bx; k++) {
				a[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!a[i][j] && !visited[i][j]) {
				int area = 0;
				DFS(i, j, area);
				v.push_back(area);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (const int a : v) cout << a << " ";
}