#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= (n - i); j++) {
			cout << ' '; // 공백 출력
		}
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		cout << '\n';
	}
}