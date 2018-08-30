import sys
import collections

answer = 0
n, m = map(int, sys.stdin.readline().split(' '))
r, c, d = map(int, sys.stdin.readline().split(' '))
area = [list(map(int, sys.stdin.readline().split(' '))) for i in range(0, n)]
dire = [[-1, 0], [0, 1], [1, 0], [0, -1]]
dq = collections.deque()
dq.append([r, c, d])#r, c, direction

if area[r][c] == 0:
    area[r][c] = 2
    answer += 1

while len(dq) > 0:
    pos = dq[0]; dq.popleft()
    if area[pos[0]][pos[1]] == 1:
        continue

    rotate4 = 0
    for i in range(0, 4):
        newdir = (pos[2]-(i+1)) % 4
        newx = pos[0]+dire[newdir][0]; newy = pos[1]+dire[newdir][1]
        if newx <= 0 or newx >= n-1 or newy <= 0 or newy >= m-1: #wall
            rotate4 += 1
            continue
        if area[newx][newy] == 0:
            dq.append([newx, newy, newdir])
            answer += 1
            area[newx][newy] = answer
            break
        else:
            rotate4 += 1

    if rotate4 == 4:
        backx = pos[0]-dire[pos[2]][0]; backy = pos[1]-dire[pos[2]][1]
        dq.append([backx, backy, pos[2]])
        if area[backx][backy] == 0:
            answer += 1
            area[backx][backy] = answer


sys.stdout.write(str(answer)+'\n')
for i in range(0, n):
    print(area[i])
