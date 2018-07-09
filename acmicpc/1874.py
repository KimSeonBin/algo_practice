from collections import deque

q = deque()
answer = []; check = True
n = int(input())
start = 1
for iter in range(0, n):
    num = int(input());
    if start < num:
        for i in range(start, num):
            q.append(i)
            answer.append('+')
        start = num+1
        answer.append('+')
        answer.append('-')
    elif start == num:
        start += 1
        answer.append('+')
        answer.append('-')
    else:
        if q[-1] == num:
            answer.append('-')
            q.pop()
        else:
            answer = [-1]
if answer[0] == -1:
    print('NO')
else:
    for item in answer:
        print(item)
# print(answer)
