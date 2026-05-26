def solution(money):
    n = len(money)
    
    # 1. 첫 번째 집을 털 수 있는 경우 (마지막 집 제외)
    dp1 = [0] * n
    dp1[0] = money[0] # 첫 번째 집을 털 기회가 있으므로 우선 선택
    dp1[1] = max(money[0], money[1]) # 첫 번째 집 vs 두 번째 집 중 더 이득인 곳 선택 (첫 집을 포기할 수도 있음)
    
    for i in range(2, n - 1): # 마지막 집(n-1)은 제외
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i])
        
    # 2. 첫 번째 집을 털 수 없는 경우 (마지막 집 포함 가능)
    dp2 = [0] * n
    dp2[0] = 0 # 첫 번째 집은 절대로 털 수 없도록 반드시 제외
    dp2[1] = money[1] # 첫 집을 못 털므로, 두 번째 집까지의 최선은 무조건 두 번째 집을 터는 것
    
    for i in range(2, n): # 마지막 집까지 포함 조사
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i])
        
    # 두  두 경우 중 최댓값 반환
    # dp1: 마지막 집 제외하므로, n-2 위치가 결과
    # dp2: 마지막 집 포함하므로, n-1 위치가 결과
    return max(dp1[n-2], dp2[n-1])