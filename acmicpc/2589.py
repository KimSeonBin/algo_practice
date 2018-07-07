from collections import deque

L, W = map(int, input().split(' '))
matrix = [[item for item in input()] for iter in range(0, L)]

q = deque()
treasure = 0
check = [[0 for i in range(0, W)] for j in range(0, L)]

v = [-1, 1]
for iter in range(0, L):
    for iter2 in range(0, W):
        if matrix[iter][iter2] == 'L':
            mostv = 0

            q.append([iter, iter2])
            while len(q) != 0:
                temp = q.popleft()
                if temp[0] + v[0] >= 0:
                    if matrix[temp[0]+v[0]][temp[1]] == 'L' and check[temp[0]+v[0]][temp[1]] == 0:
                        q.append([temp[0]+v[0], temp[1]])
                        check[temp[0]+v[0]][temp[1]] = check[temp[0]][temp[1]]+1
                        if mostv < check[temp[0]+v[0]][temp[1]]:
                            mostv = check[temp[0]+v[0]][temp[1]]
                if temp[0] + v[1] < L:
                    if matrix[temp[0]+v[1]][temp[1]] == 'L' and check[temp[0]+v[1]][temp[1]] == 0:
                        q.append([temp[0]+v[1], temp[1]])
                        check[temp[0]+v[1]][temp[1]] = check[temp[0]][temp[1]]+1
                        if mostv < check[temp[0]+v[1]][temp[1]]:
                            mostv = check[temp[0]+v[1]][temp[1]]
                if temp[1] + v[0] >= 0:
                    if matrix[temp[0]][temp[1]+v[0]] == 'L' and check[temp[0]][temp[1]+v[0]] == 0:
                        q.append([temp[0], temp[1]+v[0]])
                        check[temp[0]][temp[1]+v[0]] = check[temp[0]][temp[1]]+1
                        if mostv < check[temp[0]][temp[1]+v[0]]:
                            mostv = check[temp[0]][temp[1]+v[0]]
                if temp[1] + v[1] < W:
                    if matrix[temp[0]][temp[1]+v[1]] == 'L' and check[temp[0]][temp[1]+v[1]] == 0:
                        q.append([temp[0], temp[1]+v[1]])
                        check[temp[0]][temp[1]+v[1]] = check[temp[0]][temp[1]]+1
                        if mostv < check[temp[0]][temp[1]+v[1]]:
                            mostv = check[temp[0]][temp[1]+v[1]]
            if treasure < mostv:
                treasure = mostv
            for i in range(0, L):
                for j in range(0, W):
                    check[i][j] = 0
print(treasure)
