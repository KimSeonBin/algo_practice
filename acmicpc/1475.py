n = input()
check = [0] * 10
for i in n:
    check[int(i)] += 1
check[6] = (check[6] + check[9] + 1) // 2
check[9] = 0
print(max(check))
