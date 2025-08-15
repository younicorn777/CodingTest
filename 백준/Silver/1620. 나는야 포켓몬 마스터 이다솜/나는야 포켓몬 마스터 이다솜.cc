#include <bits/stdc++.h>
using namespace std;
int n, m, num;
string a[100004];
string name, temp;
unordered_map<string, int> table;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> name;
		table.insert({ name, i });
		a[i] = name;
	}
	for (int j = 0; j < m; j++) {
		cin >> temp;
		if (num = atoi(temp.c_str())) cout << a[num] << '\n';
		else cout << table[temp] << '\n';
	}
}