from collections import deque

for i in range(0, int(input())):
    vps = deque()
    sen = input()
    check = True
    for cha in sen:
        if cha == '(':
            vps.append('(')
        else:
            if len(vps) == 0:
                check = False
                break
            vps.pop()
    if len(vps) == 0 and check == True:
        print('YES')
    else:
        print('NO')
