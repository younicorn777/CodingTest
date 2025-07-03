#include <iostream>
#define MOD 1000000000
using namespace std;

int dp[101][10]; 

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	// 초기화
	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	
	for (int i = 2; i <= 100; i++) {
		dp[i][0] = (dp[i - 1][1]) % MOD;

		for (int j = 1; j <= 8; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;

		dp[i][9] = (dp[i - 1][8]) % MOD;
	}

	int n;
	long long result = 0ll;
	cin >> n;

	for (int i = 0; i <= 9; i++)
		result += dp[n][i];

	cout << result % MOD;
}