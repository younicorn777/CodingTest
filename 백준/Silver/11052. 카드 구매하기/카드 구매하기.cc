#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int dp[10001] = { 0 }; // 카드 i장 구매할 때의 최대 금액
	int price[10001] = { 0 }; // 카드 i개가 포함된 카드팩의 가격

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> price[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + price[j]);
		}
	}

	cout << dp[n];
}