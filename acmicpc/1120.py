a, b = input().split(' ')

answer = len(b)+1
for i in range(0, len(b)-len(a)+1):
    temp = 0
    for j in range(0, len(a)):
        if b[i+j] != a[j]:
            temp += 1
    answer = min([answer, temp])

print(answer)
