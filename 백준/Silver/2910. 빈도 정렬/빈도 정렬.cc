#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<pair<int, int>> v;
bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c;
	for (int i = 0, temp; i < n; i++) {
		bool flag = false;
		cin >> temp;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].first == temp) {
				v[i].second++;
				flag = true;
				break;
			}
		}
		if (!flag) v.push_back({ temp, 1 });
	}
	stable_sort(v.begin(), v.end(), comp);
	for (const auto& b : v) {
		for (int i = 0; i < b.second; i++) cout << b.first << ' ';
	}
}