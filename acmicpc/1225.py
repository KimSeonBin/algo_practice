n, m = input().split()
narr = [0] * 10
marr = [0] * 10

for i in n:
    narr[int(i)] += 1
for i in m:
    marr[int(i)] += 1

answer = 0
for i in range(1, 10):
    for j in range(1, 10):
        answer += i * j * narr[i] * marr[j]
print(answer)
