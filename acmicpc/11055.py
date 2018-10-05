n = int(input())
arr = []
for i in input().split(' '):
    arr.append([int(i), len(arr)])
arr = sorted(arr, key=lambda x: x[0])

answer = [0] * n

for i in range(0, n):
    for j in range(i+1, n):
        if arr[(n-1)-j][1] < arr[(n-1)-i][1] and arr[(n-1)-j][0] < arr[(n-1)-i][0]:
            answer[(n-1)-j] = max([answer[(n-1)-j], answer[(n-1)-i] + arr[(n-1)-i][0]])
    answer[(n-1)-i] += arr[(n-1)-i][0]

print(max(answer))
