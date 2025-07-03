#include <iostream>
using namespace std;

long long dp[91][2]; 

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	// 초기화
	dp[1][0] = 0; dp[1][1] = 1;
	dp[2][0] = 2; dp[2][1] = 1;

	for (int i = 3; i <= 90; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	int n;
	cin >> n;
	cout << dp[n][1];
}