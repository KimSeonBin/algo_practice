from collections import deque

m, n, k = map(int, input().split(' '))
matrix = [[0 for iter2 in range(0, n)] for iter in range(0, m)]
area = []

for iter in range(0, k):
    x, y, x2, y2 = map(int, input().split(' '))
    x_ter = x2 - x; y_ter = y2 - y
    for iterx in range(0, x_ter):
        for itery in range(0, y_ter):
            matrix[y+itery][x+iterx] = 1

vec = [-1, 1]
q = deque()
for iterx in range(0, m):
    for itery in range(0, n):
        if matrix[iterx][itery] == 0:
            temparea = 1
            matrix[iterx][itery] = 1
            q.append([iterx, itery])
            while len(q) != 0:
                temp = q.popleft()
                if temp[1] + vec[0] >= 0:
                    if matrix[temp[0]][temp[1]+vec[0]] == 0:
                        temparea += 1
                        matrix[temp[0]][temp[1]+vec[0]] = 1
                        q.append([temp[0], temp[1]+vec[0]])
                if temp[1] + vec[1] < n:
                    if matrix[temp[0]][temp[1]+vec[1]] == 0:
                        temparea += 1
                        matrix[temp[0]][temp[1]+vec[1]] = 1
                        q.append([temp[0], temp[1]+vec[1]])
                if temp[0] + vec[0] >= 0:
                    if matrix[temp[0]+vec[0]][temp[1]] == 0:
                        temparea += 1
                        matrix[temp[0]+vec[0]][temp[1]] = 1
                        q.append([temp[0]+vec[0], temp[1]])
                if temp[0] + vec[1] < m:
                    if matrix[temp[0]+vec[1]][temp[1]] == 0:
                        temparea += 1
                        matrix[temp[0]+vec[1]][temp[1]] = 1
                        q.append([temp[0]+vec[1], temp[1]])

            area.append(temparea)


area = sorted(area)
print(len(area))
for item in area:
    print(item, end=' ')
