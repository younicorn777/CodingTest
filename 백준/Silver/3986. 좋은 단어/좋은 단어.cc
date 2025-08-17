#include <bits/stdc++.h>
using namespace std;
stack<char> s;
string str;
int n, cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (char c : str) {
			if (s.empty() || s.top() != c) s.push(c);
			else s.pop();
		}
		if (s.empty()) cnt++;
		else while (!s.empty()) s.pop();
	}
	cout << cnt;
}