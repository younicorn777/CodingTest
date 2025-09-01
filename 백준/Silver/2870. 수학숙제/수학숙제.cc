#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> vec;
string go(const string& temp){
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] != '0') return temp.substr(i);
	}
	return "0";
}
bool comp(const string& s1, const string& s2) {
	if (s1.size() == s2.size()) {
		return s1 < s2;
	}
	return s1.size() < s2.size();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		string temp = "";
		for (const char c : s) {
			if (c >= '0' && c <= '9') temp += c;
			else {
				if (!temp.empty()) {
					vec.push_back(go(temp));
					temp = "";
				}
			}
		}
		if (!temp.empty()) vec.push_back(go(temp));
	}
	sort(vec.begin(), vec.end(), comp);
	for (const auto s : vec) cout << s << '\n';
}