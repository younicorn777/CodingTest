#include <bits/stdc++.h>
using namespace std;
int n, k, tall, temp, front, tail, sum;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	tall = accumulate(v.begin(), v.begin() + k, 0);
	sum = tall;
	tail = k-1;
	while (tail < v.size() - 1) {
		sum = sum - v[front++] + v[++tail];
		if (sum > tall) tall = sum;
	}
	cout << tall;
}