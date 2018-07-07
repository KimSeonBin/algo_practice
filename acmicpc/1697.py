from collections import deque

class subin:
    def __init__(self, pos, iter):
        self.pos = pos
        self.iter = iter

n, k = map(int, input().split(' '))
q = deque()
limit = 100001
pos = [0 for i in range(0, limit)]
q.append(subin(n, 1))
pos[n] = 1

while len(q) != 0:
    temp = q.popleft()
    if temp.pos == k:
        print(temp.iter-1)
        break
    if temp.pos - 1 >= 0 and pos[temp.pos-1] == 0:
        q.append(subin(temp.pos-1, temp.iter+1))
        pos[temp.pos-1] = temp.iter+1
    if temp.pos + 1 < limit and pos[temp.pos+1] == 0:
        q.append(subin(temp.pos+1, temp.iter+1))
        pos[temp.pos+1] = temp.iter+1
    if temp.pos * 2 < limit and pos[temp.pos*2] == 0:
        q.append(subin(temp.pos*2, temp.iter+1))
        pos[temp.pos*2] = temp.iter+1
