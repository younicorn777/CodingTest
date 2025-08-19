#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c;
ll Pow(int a, int b, int c) {
	if (b == 0) return 1;
	if (b == 1) return a % c;

	ll ret = Pow(a, b / 2, c);
	ret = (ret * ret) % c;
	if (b % 2 != 0) return  (ret * a) % c;
	else return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> c;
	cout << Pow(a, b, c);
}