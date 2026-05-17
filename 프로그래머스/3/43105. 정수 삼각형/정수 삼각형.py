def solution(triangle):
    dp = triangle
    n = len(triangle)
    
    for i in range(1, n):
        for j in range(len(triangle[i])):
            if j == 0:
                dp[i][j] = dp[i-1][j] + dp[i][j]
            elif j == len(triangle[i]) - 1:
                dp[i][j] = dp[i-1][j-1] + dp[i][j]
            else:
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + dp[i][j]
    
    return max(dp[n-1])
        