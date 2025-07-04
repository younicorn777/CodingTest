#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = n, k; abs(i) <= n; i--) {
		if (i == 0 || i == -1) continue;
		k = abs(i);
		
		for (int j = 0; j < n - k; j++) {
			cout << ' ';
		}
		for (int j = 0; j < (2 * k - 1); j++) {
			cout << '*';
		}
		cout << '\n';
	}
}