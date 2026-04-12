import sys
sys.setrecursionlimit(10**4)
input = sys.stdin.readline

def partition(A, left, right):
    global count

    pivot = A[right]
    index = left - 1

    for i in range(left, right):
        if(A[i] <= pivot):
            index += 1
            A[index], A[i] = A[i], A[index]
            count += 1
            if count == k:
                print(A[index], A[i])
        
    if (index + 1 != right):
        A[index + 1], A[right] = A[right], A[index + 1]
        count += 1
        if count == k:
            print(A[index+1], A[right])
    
    return index + 1

def quick_sort(A, left, right):
    if left < right:
        q = partition(A, left, right)
        quick_sort(A, left, q-1)
        quick_sort(A, q+1, right)


n,k = map(int,input().split())
array = list(map(int,input().split()))
count = 0

quick_sort(array,0,n-1)

if count < k: print(-1)