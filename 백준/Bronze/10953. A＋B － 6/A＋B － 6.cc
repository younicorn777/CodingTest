#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	char a, b;
	for (int i = 0; i < t; i++) {
		cin >> a;
		cin.ignore(1);
		cin >> b;
		cout << (a + b) - 96 << '\n';
	}
}