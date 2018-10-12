n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

for k in range(0, n):
    for i in range(0, n):
        for j in range(0, n):
            if arr[i][k] + arr[k][j] == 2:
                arr[i][j] = 1

for item in arr:
    for va in item:
        print(va, end=' ')
    print()
