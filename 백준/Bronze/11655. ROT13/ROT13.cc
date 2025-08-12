#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	getline(cin, s);
	for (char c : s) {
		if (c >= 65 && c <= 90) {
			if (c > 77) cout << (char)(c - 13);
			else cout << (char)(c + 13);
		}
		else if (c >= 97 && c <= 122) {
			if (c > 109) cout << (char)(c - 13);
			else cout << (char)(c + 13);
		}
		else cout << c;
	}
}