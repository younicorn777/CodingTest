#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	while (getline(cin, s))
		cout << s << '\n';
}