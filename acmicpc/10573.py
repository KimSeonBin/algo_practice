t = int(input())

addnum = [[0 for j in range(0, 11)] for i in range(0, 81)]
addnum[0][10] = 1
for i in range(1, 81):
    total = 0
    addnum[i][1] = addnum[i-1][10]
    total += addnum[i][1]
    for j in range(2, 10):
        addnum[i][j] = addnum[i][j-1] - addnum[i-1][j-1]
        total += addnum[i][j]
    addnum[i][10] = total

for iter in range(0, t):
    num = input()
    check = True
    for i in range(0, len(num)-1):
        if num[i] > num[i+1]:
            check = False
    if check is False:
        print(-1)
        continue

    numlen = len(num)
    answer = 0
    for i in range(0, numlen):
        answer += addnum[i][10]
    ftemp = int(num[0])
    for i in range(1, ftemp):
        answer += addnum[numlen][i]
    for index in range(0, numlen-1):
        fnum = int(num[index]); lnum = int(num[index+1])
        distance = lnum - fnum
        for i in range(fnum, fnum+distance):
            answer += addnum[(numlen-1) - index][i]

    print(answer)
