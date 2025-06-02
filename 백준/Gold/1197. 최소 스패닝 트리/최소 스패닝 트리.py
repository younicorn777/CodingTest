import sys
input = sys.stdin.readline

parent = []

def init_set(nSets):
    global parent
    parent = [-1] * nSets

def find(id):
    if parent[id] < 0:
        return id
    parent[id] = find(parent[id])  # path compression
    return parent[id]

def union(s1, s2):
    parent[s1] = s2

def MSTKruskal(vsize, eList):
    eList.sort(key=lambda e: e[2])  # 가중치 오름차순
    total_weight = 0
    edgeAccepted = 0

    for e in eList:
        uset = find(e[0])
        vset = find(e[1])
        if uset != vset:
            union(uset, vset)
            total_weight += e[2]
            edgeAccepted += 1
            if edgeAccepted == vsize - 1:
                break

    return total_weight

V, E = map(int, input().split())
init_set(V)

edges = []
for _ in range(E):
    a, b, c = map(int, input().split())
    edges.append((a - 1, b - 1, c))  # 0-index로 맞춤

result = MSTKruskal(V, edges)
print(result)