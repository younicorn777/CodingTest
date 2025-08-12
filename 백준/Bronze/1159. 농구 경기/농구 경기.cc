#include <bits/stdc++.h>
using namespace std;
int a[26], n;
string s;
vector<char> ret;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s; a[s[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) if (a[i] >= 5) ret.push_back(i +'a');
	if (ret.size()) for (char c : ret) cout << c;
	else cout << "PREDAJA";
}