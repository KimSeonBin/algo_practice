import sys
t = int(sys.stdin.readline())
answer = []
for iter in range(0, t):
    a, b = map(int, sys.stdin.readline().split(' '))
    answer.append(pow((a//b), 2))
sys.stdout.write('\n'.join(map(str, answer)))
