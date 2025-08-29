#include <bits/stdc++.h>
using namespace std;
int n, m, j, first, last, temp, cnt, ret;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> j; 
	first = 1; last = m;
	for (int i = 0; i < j; i++) {
		cnt = 0;
        cin >> temp;
		if (temp < first) {
			cnt = first - temp;
			first -= cnt;
			last -= cnt;
		}
		if (temp > last) {
			cnt = temp - last;
			first += cnt;
			last += cnt;
		}
		ret += cnt;
	}
	cout << ret;
}