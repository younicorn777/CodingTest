#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> s) {
		if (s == "end") break;
		int vcnt = 0, ccnt = 0; // 모음수 자음수
		bool ret = true, v = false;
		stack<char> _stack;
		for(const char c : s){
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				v = true;
				vcnt++; ccnt = 0;
				if (!_stack.empty()) {
					if (vcnt >= 3 || (c != 'e' && c != 'o' && _stack.top() == c)) {
						ret = false;
						break;
					}
				}
			}
			else {
				vcnt = 0; ccnt++;
				if (!_stack.empty()) {
					if (ccnt >= 3 || _stack.top() == c) {
						ret = false;
						break;
					}
				}
			}
			_stack.push(c);
		}
		if (ret == true && v == true) cout << '<' << s << '>' << " is acceptable.\n";
		else cout << '<' << s << '>' << " is not acceptable.\n";
	}
}