#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> n) {
		int cnt = 1, temp = 1;
		while (temp < n) {
			temp = temp * 10 + 1;
			cnt++;
		}
		while (1) {
			if (temp % n == 0) break;
			temp = temp % n;
			temp = temp * 10 + 1;
			cnt++;
		}
		cout << cnt << '\n';
	}
}