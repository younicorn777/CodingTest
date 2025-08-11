#include <bits/stdc++.h>
using namespace std;
int alpha[26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	getline(cin, s);
	for (char i : s) alpha[i - 'a']++;
	for (int i : alpha) cout << i << ' ';
}