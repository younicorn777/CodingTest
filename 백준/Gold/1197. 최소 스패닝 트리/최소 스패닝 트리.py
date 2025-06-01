import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**6)

def find(x):
    if parent[x] < 0:
        return x
    parent[x] = find(parent[x])  # 경로 압축
    return parent[x]

def union(x, y):
    x_root = find(x)
    y_root = find(y)
    if x_root == y_root:
        return False
    parent[y_root] = x_root  # 그냥 y_root를 x_root 밑에 붙이기
    return True

v, e = map(int, input().split())
parent = [-1] * (v + 1)
edges = []

for _ in range(e):
    a, b, c = map(int, input().split())
    edges.append((a, b, c))

edges.sort(key=lambda x: x[2])  # 가중치 기준 정렬

weight_sum = 0
edge_count = 0

for a, b, c in edges:
    if union(a, b):
        weight_sum += c
        edge_count += 1
        if edge_count == v - 1:
            break

print(weight_sum)