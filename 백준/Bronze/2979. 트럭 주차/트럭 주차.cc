#include <bits/stdc++.h>
using namespace std;
int a, b, c, t[104], t1,t2, sum;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		cin >> t1 >> t2;
		for (int j = t1; j < t2; j++) t[j]++;
	}
	for (int i = 1; i <= 100; i++) {
		if (t[i] == 1) sum += (t[i] * a);
		if (t[i] == 2) sum += (t[i] * b);
		if (t[i] == 3) sum += (t[i] * c);
	}
	cout << sum;
}