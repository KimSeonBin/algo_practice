import sys
x, y = map(int, sys.stdin.readline().split(' '))
n = int(sys.stdin.readline())
xa = 0; ya = 0; dis = 300000000
for i in range(0, n):
    xp, yp = map(int, sys.stdin.readline().split(' '))
    if dis > abs(x-xp)+abs(y-yp):
        xa, ya, dis = xp, yp, abs(x-xp)+abs(y-yp)
print(str(xa) + ' ' + str(ya))
