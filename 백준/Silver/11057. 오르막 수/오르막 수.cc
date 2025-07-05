#include <iostream>
#define MOD 10007
using namespace std;

int dp[1001][10] = { 0 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	// 초기화
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] += dp[i - 1][k] % MOD;
			}
		}
	}

	int n, sum = 0;
	cin >> n;

	for (int i = 0; i < 10; i++)
		sum += dp[n][i];

	cout << (sum % MOD);
}