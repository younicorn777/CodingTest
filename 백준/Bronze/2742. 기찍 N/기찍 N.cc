#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = n; i >= 1; i--)
		cout << i << '\n';
}