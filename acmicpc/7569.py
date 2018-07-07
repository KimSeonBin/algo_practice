from collections import deque

tomato = deque()
matrix = []
day = 0
ripeTomato = 0; emptyspace = 0
m, n, h = map(int, input().split(' '))

for iter in range(0, h):
    htemp = []
    for iter2 in range(0, n):
        temp = list(map(int, input().split(' ')))

        for index in range(0, m):
            if temp[index] == 1:
                tomato.append([index, iter2, iter])
                ripeTomato += 1
            elif temp[index] == -1:
                emptyspace += 1
        htemp.append(temp)
    matrix.append(htemp)

vec = [-1, 1]

while len(tomato) != 0:
    if ripeTomato == m * n * h - emptyspace:
        break

    tomatolen = len(tomato)

    for i in range(0, tomatolen):
        loc = tomato.popleft()

        #up
        if loc[0] + vec[0] >= 0:
            if matrix[loc[2]][loc[1]][loc[0]+vec[0]] == 0:
                tomato.append([loc[0]+vec[0], loc[1], loc[2]])
                matrix[loc[2]][loc[1]][loc[0]+vec[0]] = 1
                ripeTomato += 1
        #down
        if loc[0] + vec[1] < m:
            if matrix[loc[2]][loc[1]][loc[0]+vec[1]] == 0:
                tomato.append([loc[0]+vec[1], loc[1], loc[2]])
                matrix[loc[2]][loc[1]][loc[0]+vec[1]] = 1
                ripeTomato += 1
        #left
        if loc[1] + vec[0] >= 0:
            if matrix[loc[2]][loc[1]+vec[0]][loc[0]] == 0:
                tomato.append([loc[0], loc[1]+vec[0], loc[2]])
                matrix[loc[2]][loc[1]+vec[0]][loc[0]] = 1
                ripeTomato += 1
        #right
        if loc[1] + vec[1] < n:
            if matrix[loc[2]][loc[1]+vec[1]][loc[0]] == 0:
                tomato.append([loc[0], loc[1]+vec[1], loc[2]])
                matrix[loc[2]][loc[1]+vec[1]][loc[0]] = 1
                ripeTomato += 1
        #foward
        if loc[2] + vec[0] >= 0:
            if matrix[loc[2]+vec[0]][loc[1]][loc[0]] == 0:
                tomato.append([loc[0], loc[1], loc[2]+vec[0]])
                matrix[loc[2]+vec[0]][loc[1]][loc[0]] = 1
                ripeTomato += 1
        #back
        if loc[2] + vec[1] < h:
            if matrix[loc[2]+vec[1]][loc[1]][loc[0]] == 0:
                tomato.append([loc[0], loc[1], loc[2]+vec[1]])
                matrix[loc[2]+vec[1]][loc[1]][loc[0]] = 1
                ripeTomato += 1
    day += 1
    
if ripeTomato != m * n * h - emptyspace:
    print(-1)
else:
    print(day)
