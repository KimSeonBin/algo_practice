from collections import deque

q = deque()
m, n = map(int, input().split())
alltime = 0; lastcheese = 0

allcheese = 0; deletecheese = 0;
matrix = [list(map(int, input().split()))for iter in range(0, m)]
for item in matrix:
    for detail in item:
        if detail == 1:
            allcheese += 1
iter = 1
vec1 = [1,0,-1,0]
vec2 = [0,1,0,-1]

while True:
    q.append([0, 0])
    while len(q) != 0:
        temp = q.popleft()
        for i in range(0, 4):
            if temp[0] + vec1[i] >= 0 and temp[0] + vec1[i] < m and + \
            temp[1] + vec2[i] >= 0 and temp[1] + vec2[i] < n:
                if matrix[temp[0]+vec1[i]][temp[1]+vec2[i]] == 0:
                    q.append([temp[0]+vec1[i], temp[1]+vec2[i]])
                    matrix[temp[0]+vec1[i]][temp[1]+vec2[i]] = 'x'
                if matrix[temp[0]+vec1[i]][temp[1]+vec2[i]] == 1:
                    lastcheese += 1
                    matrix[temp[0]+vec1[i]][temp[1]+vec2[i]] = 'x'

    if allcheese == deletecheese + lastcheese:
        print(iter)
        print(lastcheese)
        break
    iter += 1
    deletecheese += lastcheese
    lastcheese = 0
    for i in range(0, m):
        for j in range(0, n):
            if matrix[i][j] == 'x':
                matrix[i][j] = 0
