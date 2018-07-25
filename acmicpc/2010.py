import sys
n = int(sys.stdin.readline().rstrip())
answer = 0
for i in range(0, n):
    answer += int(sys.stdin.readline().rstrip()) - 1
print(answer+1)
