a = input()
b = input()

dp = [[0 for i in range(1001)] for j in range(1001)]

for i in range(0, len(a)):
    for j in range(0, len(b)):
        if a[i] == b[j]:
            dp[i+1][j+1] = dp[i][j] + 1
        else:
            dp[i+1][j+1] = max([dp[i+1][j], dp[i][j+1]])

print(dp[len(a)][len(b)])
