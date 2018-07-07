from collections import deque

m, n = map(int, input().split(' '))
matrix = [list(map(int, input().split(' '))) for i in range(0, m)]
check = [[[False for k in range(0, 4)]for j in range(0, n)] for i in range(0, m)]
start = list(map(int, input().split(' ')))
end = list(map(int, input().split(' ')))
q = deque()
for i in range(0, len(start)):
    start[i] -= 1
    end[i] -= 1
start.append(0)

q.append(start)
check[start[0]][start[1]][start[2]] = True

vec1 = [0,0,1,-1]; vec2 = [1,-1,0,0]
#dir = [0,1,2,3]

if start[0] == end[0] and start[1] == end[1] and start[2] == end[2]:
    print(0)
    exit()

incheck = False
while len(q) != 0:
    temp = q.popleft()
    #직진 1~3칸 이동
    for i in range(1, 4):
        sx = temp[0]+vec1[temp[2]]*i
        sy = temp[1]+vec2[temp[2]]*i
        if sx >= 0 and sx < m and sy >= 0 and sy < n:
            if matrix[sx][sy] == 1:
                break
            if matrix[sx][sy] == 0 and check[sx][sy][temp[2]] == False:
                q.append([sx, sy, temp[2], temp[3]+1])
                # print([sx, sy, temp[2], temp[3]+1], end='go\n')
                check[sx][sy][temp[2]] = True
                if check[end[0]][end[1]][end[2]] == True:
                    print(temp[3]+1)
                    incheck = True
                    break
    if incheck == True:
        break
    #턴
    right = 0; left = 0
    if temp[2] >= 0 and temp[2] <= 1:
        right = 3; left = 2
    else:
        right = 1; left = 0
    if check[temp[0]][temp[1]][right] == False:
        q.append([temp[0], temp[1], right, temp[3]+1])
        check[temp[0]][temp[1]][right] = True
        # print([temp[0], temp[1], right, temp[3]+1], end='right\n')
        if check[end[0]][end[1]][end[2]] == True:
            print(temp[3]+1)
            break
    if check[temp[0]][temp[1]][left] == False:
        q.append([temp[0], temp[1], left, temp[3]+1])
        check[temp[0]][temp[1]][left] = True
        # print([temp[0], temp[1], left, temp[3]+1], end='left\n')
        if check[end[0]][end[1]][end[2]] == True:
            print(temp[3]+1)
            break
