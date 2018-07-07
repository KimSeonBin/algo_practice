from collections import deque

q = deque()
m, n = map(int, input().split())
alltime = 0; lastcheese = 0

allcheese = 0; deletecheese = 0;
matrix = [list(map(int, input().split())) for iter in range(0, m)]
for item in matrix:
    for detail in item:
        if detail == 1:
            allcheese += 1
iter = 1
vec1 = [1,0,-1,0]
vec2 = [0,1,0,-1]

while True:
    q.append([0, 0])
    matrix[0][0] = 'x'
    deletelist = []
    while len(q) != 0:
        temp = q.popleft()
        for i in range(0, 4):
            if temp[0] + vec1[i] >= 0 and temp[0] + vec1[i] < m and + \
            temp[1] + vec2[i] >= 0 and temp[1] + vec2[i] < n:
                if matrix[temp[0]+vec1[i]][temp[1]+vec2[i]] == 0:
                    q.append([temp[0]+vec1[i], temp[1]+vec2[i]])
                    matrix[temp[0]+vec1[i]][temp[1]+vec2[i]] = 'x'

    for i in range(0, m):
        for j in range(0, n):
            if matrix[i][j] == 1:
                check = 0
                for k in range(0, 4):
                    if i + vec1[k] >= 0 and i + vec1[k] < m and + \
                    j + vec2[k] >= 0 and j + vec2[k] < n:
                        if matrix[i+vec1[k]][j+vec2[k]] == 'x':
                            check += 1
                if check >= 2:
                    deletelist.append([i, j])
                    lastcheese += 1

    if allcheese <= deletecheese + lastcheese:
        print(iter)
        break
    iter += 1
    deletecheese += lastcheese
    lastcheese = 0
    for i in range(0, m):
        for j in range(0, n):
            if matrix[i][j] == 'x':
                matrix[i][j] = 0

    for item in deletelist:
        matrix[item[0]][item[1]] = 0
