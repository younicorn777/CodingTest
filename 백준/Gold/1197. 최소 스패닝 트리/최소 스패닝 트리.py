import heapq
import sys

# 입력 속도 향상
input = sys.stdin.readline

V, E = map(int, input().split())
adj = [[] for _ in range(V + 1)]
visited = [False] * (V + 1)

for _ in range(E):
    u, v, w = map(int, input().split())
    adj[u].append((w, v))
    adj[v].append((w, u))

def prim(start):
    pq = [(0, start)] # (가중치, 정점)
    total_weight = 0
    cnt = 0 # 연결된 정점 수
    
    while pq:
        if cnt == V: break # 모든 정점을 다 연결하면 종료
        
        weight, curr = heapq.heappop(pq)
        
        if visited[curr]:
            continue
            
        visited[curr] = True
        total_weight += weight
        cnt += 1
        
        for n_weight, nxt in adj[curr]:
            if not visited[nxt]:
                heapq.heappush(pq, (n_weight, nxt))
                
    return total_weight

print(prim(1))