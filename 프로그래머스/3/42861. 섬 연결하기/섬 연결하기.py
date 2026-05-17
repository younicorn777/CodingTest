def solution(n, costs):
    
    # 부모 노드 저장
    parent = [i for i in range(n)]
    
    # 부모 찾기
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    
    # 두 집합 연결
    def union(a, b):
        a = find(a)
        b = find(b)
        
        if a < b:
            parent[b] = a
        else:
            parent[a] = b
    
    # 비용 기준 정렬
    costs.sort(key=lambda x: x[2])
    
    answer = 0
    
    for a, b, cost in costs:
        # 사이클이 발생하지 않는 경우 연결
        if find(a) != find(b):
            union(a, b)
            answer += cost
    
    return answer