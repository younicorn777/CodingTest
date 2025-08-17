#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> table;
int t, n, ret;
string a, b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		ret = 1;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			table[b]++;
		}
		for (const auto& t : table)
			ret *= (t.second + 1);
		cout << ret - 1 << '\n';
		table.clear();
	}
}