#include <bits/stdc++.h>
using namespace std;
string s, t1,t2, temp;
int it, a, n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	it = s.find('*');
	t1 = s.substr(0, it);
	t2 = s.substr(it + 1);
	a = t2.size();

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (t1.size() + t2.size() > temp.size()) {
			cout << "NE\n";
			continue;
		}
		if (temp.substr(0, it) == t1 && temp.substr(temp.size() - a) == t2) cout << "DA\n";
		else cout << "NE\n";
	}
}