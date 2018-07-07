from collections import deque
lottolen = 6
num = []; numlen = 0
q = deque()

def recur(index):
    global lottolen
    for i in range(index, numlen):
        q.append(num[i])
        if len(q) == lottolen:
            for item in q:
                print(item, end=' ')
            print()
            q.pop()
        else:
            recur(i+1)
            q.pop()

while True:
    inputt = list(map(int, input().split(' ')))
    if inputt[0] == 0:
        break

    num = inputt[1::]; numlen = inputt[0]
    for i in range(0, numlen - 5):
        q.append(num[i])
        recur(i+1)
        while len(q) != 0:
            q.pop()
    print()
