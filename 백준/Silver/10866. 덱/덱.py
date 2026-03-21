import sys
input = sys.stdin.readline

class CircularDeque:
    def __init__(self, capacity):
        self.capacity = capacity
        self.array = [None] * capacity
        self.f = 0  
        self.r = 0 

    def isEmpty(self):
        return 1 if self.f == self.r else 0

    def isFull(self):
        return 1 if self.f == (self.r + 1) % self.capacity else 0

    def push_front(self, item):
        if not self.isFull():
            self.array[self.f] = item
            self.f = (self.f - 1 + self.capacity) % self.capacity

    def push_back(self, item):
        if not self.isFull():
            self.r = (self.r + 1) % self.capacity
            self.array[self.r] = item

    def pop_front(self):
        if self.isEmpty(): return -1
        self.f = (self.f + 1) % self.capacity
        return self.array[self.f]

    def pop_back(self):
        if self.isEmpty(): return -1
        item = self.array[self.r]
        self.r = (self.r - 1 + self.capacity) % self.capacity
        return item

    def size(self):
        return (self.r - self.f + self.capacity) % self.capacity

    def front(self):
        if self.isEmpty(): return -1
        return self.array[(self.f + 1) % self.capacity]

    def back(self): 
        if self.isEmpty(): return -1
        return self.array[self.r]


n = int(input())
dq = CircularDeque(10005) 

for _ in range(n):
    line = input().split()
    cmd = line[0]

    if cmd == "push_front":  dq.push_front(int(line[1]))
    elif cmd == "push_back": dq.push_back(int(line[1]))
    elif cmd == "pop_front": print(dq.pop_front())
    elif cmd == "pop_back":  print(dq.pop_back())
    elif cmd == "size":      print(dq.size())
    elif cmd == "empty":     print(dq.isEmpty())
    elif cmd == "front":     print(dq.front())
    elif cmd == "back":      print(dq.back())