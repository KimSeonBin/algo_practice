from collections import deque
n, x = map(int, input().split(' '))
total = (n-2) * (n-1) / 2
filled = 0
answer = deque()
if(total < x):
    print(-1)
else:
    shift = 0; shiftcount = 1
    answer.append(n-1)
    while total > x:
        shift = shiftcount
        shiftcount += 1
        total -= shift
        answer.append(n-shiftcount)
    filled = total

    #answer
    print(n, end=' ')
    for i in range(1, n - shiftcount):
        print(i, end=' ')

    if len(answer) != 0:
        check = answer.pop()
        ctemp = True
        for item in answer:
            if filled + (item - check) == x:
                print(check, end=' ')
                ctemp = False
            print(item, end=' ')
        if ctemp is True:
            print(check, end=' ')
        print()
