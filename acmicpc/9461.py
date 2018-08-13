p = [1, 1, 1]
for i in range(0, 100):
    p.append(p[-2] + p[-3])

n = int(input())
for i in range(0, n):
    index = int(input())
    print(p[index-1])
