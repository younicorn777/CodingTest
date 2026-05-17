from collections import deque

def solution(n, computers):
    
    visited = [False] * n
    answer = 0
    
    for i in range(n):
        
        # 방문하지 않은 경우
        if not visited[i]:
            queue = deque()
            queue.append(i)
            visited[i] = True
            
            while queue:    
                current = queue.popleft()
                for j in range(n):
                    if computers[current][j] == 1 and not visited[j]:
                        queue.append(j)
                        visited[j] = True
            answer += 1
    
    return answer