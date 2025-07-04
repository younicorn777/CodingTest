#include <iostream>
#include <string>
using namespace std;

int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
string day[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int date_sum = 0;
	int x, y;
	cin >> x >> y;

	for (int i = 0; i < x - 1; i++)
		date_sum += month[i];
	date_sum += y;

	cout << day[date_sum % 7];
}