def solution(tickets):
    
    answer = []   # 가능한 경로 모두 저장
    visited = [False] * len(tickets) # 방문 확인
    
    def dfs(airport, path):
        
        # 모든 항공권을 사용한 경우
        if len(path) == len(tickets) + 1:
            answer.append(path)
            return
        
        # 연결된 항공권 탐색
        for idx, ticket in enumerate(tickets):   
            
            # 출발 공항이 같고 아직 방문하지 않은 경우
            if ticket[0] == airport and not visited[idx]:
                visited[idx] = True # 방문 표시
                dfs(ticket[1], path + [ticket[1]]) # 다음 공항 탐색
                visited[idx] = False # 백트래킹
    
    dfs("ICN", ["ICN"]) # ICN 공항부터 탐색 시작
    answer.sort() # 사전순 정렬
    return answer[0]