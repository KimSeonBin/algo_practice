import sys
sen = sys.stdin.readline().split()

kx, ky = (ord(sen[0][0])-64), int(sen[0][1])
sx, sy = (ord(sen[1][0])-64), int(sen[1][1])
n = int(sen[2])

# board[i][j] = 1 -> king, 2 -> stone
board = [[0 for i in range(0, 10)] for j in range(0, 10)]
board[kx][ky] = 1; board[sx][sy] = 2
dirr = [[1, 0], [-1, 0], [0, -1], [0, 1], [1, 1], [-1, 1], [1, -1], [-1, -1]]
for i in range(0, n):
    move = sys.stdin.readline().strip()
    index = -1
    if move == 'R':
        index = 0
    elif move == 'L':
        index = 1
    elif move == 'B':
        index = 2
    elif move == 'T':
        index = 3
    elif move == 'RT':
        index = 4
    elif move == 'LT':
        index = 5
    elif move == 'RB':
        index = 6
    else:
        index = 7

    nkx, nky = kx + dirr[index][0], ky + dirr[index][1]
    if nkx <= 0 or nkx >= 9 or nky <= 0 or nky >= 9:
        continue
    if nkx == sx and nky == sy:
        nsx, nsy = sx + dirr[index][0], sy + dirr[index][1]
        if nsx <= 0 or nsx >= 9 or nsy <= 0 or nsy >= 9:
            continue
        sx, sy = nsx, nsy
    kx, ky = nkx, nky

print(str(chr(kx+64)) + str(ky))
print(str(chr(sx+64)) + str(sy))
