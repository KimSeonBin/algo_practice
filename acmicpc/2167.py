import sys
n, m = map(int, sys.stdin.readline().split(' '))
matrix = [list(map(int, sys.stdin.readline().split(' '))) for i in range(0, n)]
dp = [[0 for j in range(0, m+1)] for i in range(0, n+1)]
for i in range(0, n):
    dp[i+1][1] = matrix[i][0]
    for j in range(0, m):
        dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + matrix[i][j]

for iter in range(0, int(sys.stdin.readline())):
    i, j, x, y = map(int, sys.stdin.readline().split(' '))
    sys.stdout.write(str(dp[x][y]-dp[x][j-1]-dp[i-1][y]+dp[i-1][j-1])+'\n')
