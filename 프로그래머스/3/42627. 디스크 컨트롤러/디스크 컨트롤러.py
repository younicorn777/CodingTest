import heapq

def solution(jobs):
    
    answer = 0
    now = 0          # 현재 시간
    count = 0        # 처리한 작업 개수
    start = -1       # 이전 작업 완료 시간
    
    heap = []
    
    # 모든 작업 처리할 때까지 반복
    while count < len(jobs):
        
        # 현재 시간까지 요청된 작업 탐색
        for job in jobs:
            request = job[0]
            work = job[1]
            
            # 아직 처리하지 않은 작업인 경우
            if start < request <= now:
                heapq.heappush(heap, [work, request])
        
        # 실행 가능한 작업이 있는 경우
        if heap:
            current = heapq.heappop(heap)
            
            work = current[0]
            request = current[1]
            
            start = now
            now += work
            
            # 반환 시간 계산
            answer += (now - request)
            count += 1
        
        # 실행 가능한 작업이 없는 경우
        else:
            now += 1
    
    return answer // len(jobs)