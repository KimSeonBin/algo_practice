n, k = map(int, input().split(' '))
g = [int(str(n*i)[::-1]) for i in range(1, k+1)]
print(max(g))
