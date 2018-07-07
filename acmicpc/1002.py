import math
t = int(input())

for iter in range(0, t):
    x1, y1, r1, x2, y2, r2 = map(int, input().split(' '))

    dis = math.sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
    mv = 0; lv = 0
    if r2 > r1:
        mv = r2; lv = r1
    else:
        mv = r1; lv = r2

    if x1 == x2 and y1 == y2 and r1 == r2:#두 원이 같을 때
        print(-1)
    elif dis > r1+r2:#두 원이 만나지 않을 때
        print(0)
    elif dis == r1+r2:#두 원이 인접할 때
        print(1)
    elif dis+lv < mv:#한 원이 다른 원 안에 있을 때
        print(0)
    elif dis+lv == mv:#한 원이 다른 원 안에서 인접할 때
        print(1)
    elif dis < r1+r2:#다른 원이 2점에서 만날 떄
        print(2)
