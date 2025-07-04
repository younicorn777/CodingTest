#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	string s;
	getline(cin, s);
	int idx = 0;

	while (s[idx]) {
		cout << s[idx++];
		if (idx % 10 == 0) cout << '\n';
	}
}