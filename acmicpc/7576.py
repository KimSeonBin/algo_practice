from collections import deque

m, n = input().split(' ')
m = int(m); n = int(n)
matrix = []
tomato = deque()
ripeTomato = 0; emptyspace = 0
day = 0
for iter in range(0, n):
    temp = list(map(int, input().split()))
    lentemp = len(temp)
    for i in range(0, lentemp):
        if temp[i] == 1:
            tomato.append([iter, i])
            ripeTomato += 1
        elif temp[i] == -1:
            emptyspace += 1
    matrix.append(temp)

vec = [-1, 1]

while len(tomato) != 0:
    if ripeTomato == m * n - emptyspace:
        break

    tomatolen = len(tomato)
    for i in range(0, tomatolen):
        loc = tomato.popleft()
        #up
        if loc[0] + vec[0] >= 0:
            if matrix[loc[0]+vec[0]][loc[1]] == 0:
                tomato.append([loc[0]+vec[0], loc[1]])
                matrix[loc[0]+vec[0]][loc[1]] = 1
                ripeTomato += 1
        #down
        if loc[0] + vec[1] < n:
            if matrix[loc[0]+vec[1]][loc[1]] == 0:
                tomato.append([loc[0]+vec[1], loc[1]])
                matrix[loc[0]+vec[1]][loc[1]] = 1
                ripeTomato += 1
        #left
        if loc[1] + vec[0] >= 0:
            if matrix[loc[0]][loc[1]+vec[0]] == 0:
                tomato.append([loc[0], loc[1]+vec[0]])
                matrix[loc[0]][loc[1]+vec[0]] = 1
                ripeTomato += 1
        #right
        if loc[1] + vec[1] < m:
            if matrix[loc[0]][loc[1]+vec[1]] == 0:
                tomato.append([loc[0], loc[1]+vec[1]])
                matrix[loc[0]][loc[1]+vec[1]] = 1
                ripeTomato += 1
    day += 1

if ripeTomato != m * n - emptyspace:
    print(-1)
else:
    print(day)
