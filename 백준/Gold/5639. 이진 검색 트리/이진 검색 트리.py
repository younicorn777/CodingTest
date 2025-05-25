import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

#후위 순회
def postorder(root_idx, last_idx):
    #탈출 조건 
    if root_idx > last_idx:
        return
    
    root = preorder[root_idx] #루트 노드의 키
    rsub_start_idx = root_idx + 1 #오른쪽 서브트리의 시작점
    
    while (rsub_start_idx <= last_idx) :
        
        #루트 노드 보다 큰 키가 나온 지점 : 오른쪽 서브트리의 시작점
        if(preorder[rsub_start_idx] > root) :
            break
        
        rsub_start_idx += 1 
            
    postorder(root_idx + 1, rsub_start_idx - 1) #왼쪽 서브 트리
    postorder(rsub_start_idx, last_idx) #오른쪽 트리
    print(root) #루트 노드의 키

#프로그램 실행
preorder = []

while True:
    try:
        preorder.append(int(input()))
    except:
        break

postorder(0, len(preorder) - 1)