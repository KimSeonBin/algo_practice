def search(a, b, ar, how):
    result = 0
    for i in range(0, a):
        temp = 0

        for j in range(0, b):
            if how == 0:
                if ar[i][j] == 'X':
                    temp += 1
            else:
                if ar[j][i] == 'X':
                    temp += 1
        if not temp:
            result += 1

    return result


n, m = map(int, input().split(' '))

arr = [input() for i in range(0, n)]

a_zero = search(n, m, arr, 0)
b_zero = search(m, n, arr, 1)

print(max(a_zero, b_zero))
