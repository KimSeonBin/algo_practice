import sys
n, w, h = map(int, sys.stdin.readline().split(' '))
ma = w*w + h*h
for i in range(0, n):
    if ma < int(sys.stdin.readline()) ** 2:
        sys.stdout.write("NO\n")
    else:
        sys.stdout.write("YES\n")
