#include <bits/stdc++.h>
using namespace std;
int alpha[26], ocnt, oidx = -1;
string s;
deque<char> d;
bool test(){
	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 != 0) {
			ocnt++;
			oidx = i;
		}
	}
	return ocnt <= (s.size() % 2);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	for (char c : s) alpha[c - 'A']++;
	if (test()) {
		if(oidx != -1) d.push_back(oidx + 'A');
		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j < (alpha[i] / 2); j++) {
				d.push_front(i + 'A');
				d.push_back(i + 'A');
			}
		}
		for (char c : d) cout << c;
		return 0;
	}
	else cout << "I'm Sorry Hansoo";
}