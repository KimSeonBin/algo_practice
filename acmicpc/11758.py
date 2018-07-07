# CCW 알고리즘
# https://www.acmicpc.net/blog/view/27
# ccw = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)

p1 = input().split(' ')
p2 = input().split(' ')
p3 = input().split(' ')
p1 = [float(p1[i]) for i in range(0, 2)]
p2 = [float(p2[i]) for i in range(0, 2)]
p3 = [float(p3[i]) for i in range(0, 2)]

ccw = (p2[0] - p1[0])*(p3[1] - p1[1]) - (p2[1] - p1[1])*(p3[0] - p1[0])
if ccw == 0:
    print(0)
elif ccw > 0:
    print(1)
else:
    print(-1)
