#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n - i; j++) {
			cout << ' ';
		}
		if (i == 1 || i == n) {
			for (int j = 0; j < (2 * i - 1); j++) {
				cout << '*';
			}
		}
		else {
			for (int j = 0; j < (2 * i - 1); j++) {
				if (j == 0 || j == 2 * i - 2)
					cout << '*';
				else
					cout << ' ';
			}
		}
		cout << '\n';
	}
}