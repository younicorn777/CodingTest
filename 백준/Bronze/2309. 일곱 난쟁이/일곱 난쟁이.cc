#include <bits/stdc++.h>
using namespace std;
vector<int> v, b;
int temp;
void test() {
	int sum = accumulate(b.begin(), b.end(), 0);
	if (sum == 100) {
		sort(b.begin(), b.end());
		for (int i : b) cout << i << '\n';
		exit(0);
	}
}
void cobi(int start) {
	if (b.size() == 7) test();
	for (int i = start + 1; i < 9; i++) {
		b.push_back(v[i]);
		cobi(i);
		b.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for(int i = 0; i < 9; i++){
		cin >> temp;
		v.push_back(temp);
	}
	cobi(-1);
}