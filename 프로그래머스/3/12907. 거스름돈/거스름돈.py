def solution(n, money):
    dp = [0] * (n + 1)
    dp[0] = 1  # 0원을 만드는 방법은 1가지

    for coin in money:
        for i in range(coin, n + 1):
            dp[i] += dp[i - coin]
            dp[i] %= 1000000007

    return dp[n]
