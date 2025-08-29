#include <bits/stdc++.h>
using namespace std;
const int max_n = 68;
int a[max_n][max_n], n;
string s;
void go(int y, int x, int size) {
	int first = a[y][x];
	bool flag = true;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (a[i][j] != first) flag = false;
		}
	}
	if (flag) cout << first;
	else {
		cout << '(';
		go(y, x, size / 2);
		go(y, x + size / 2, size / 2);
		go(y + size / 2, x, size / 2);
		go(y + size / 2, x + size / 2, size / 2);
		cout << ')';
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) a[i][j] = s[j] - '0';
	}
	go(0, 0, n);
}