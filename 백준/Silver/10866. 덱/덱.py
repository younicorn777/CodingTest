import collections
import sys

input = sys.stdin.readline

n = int(input())
dq = collections.deque() 

for _ in range(n):
    line = input().split()
    cmd = line[0]

    if cmd == "push_front":  dq.appendleft(int(line[1]))
    elif cmd == "push_back": dq.append(int(line[1]))
    elif cmd == "pop_front": print(dq.popleft() if dq else -1)     
    elif cmd == "pop_back":  print(dq.pop() if dq else -1)     
    elif cmd == "size":      print(len(dq))
    elif cmd == "empty":     print(0 if dq else 1)
    elif cmd == "front":     print(dq[0] if dq else -1)
    elif cmd == "back":      print(dq[-1] if dq else -1)  