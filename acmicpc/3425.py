# -a mod b 일때 처리
import collections

def isvalid1(a):
    if abs(a) > 1000000000:
        return False
    return True

while True:
    st = []
    n = 0
    quit = False

    while True:
        temp = input()
        if temp == 'QUIT':
            quit = True
            break
        if temp == 'END':
            break
        st.append(temp.split(' '))

    if quit:
        break

    for i in range(0, int(input())):
        dq = collections.deque()
        dq.append(int(input()))

        err = False

        for j in range(0, len(st)):
            if st[j][0] == 'NUM':
                dq.append(int(st[j][1]))
            elif st[j][0] == 'POP':
                if len(dq) > 0:
                    dq.pop()
                else:
                    err = True
            elif st[j][0] == 'INV':
                if len(dq) > 0:
                    dq[-1] *= -1
                else:
                    err = True
            elif st[j][0] == 'DUP':
                if len(dq) > 0:
                    dq.append(dq[-1])
                else:
                    err = True
            elif st[j][0] == 'SWP':
                if len(dq) > 1:
                    dq[-1], dq[-2] = dq[-2], dq[-1]
                else:
                    err = True
            elif st[j][0] == 'ADD':
                if len(dq) > 1:
                    te = dq[-1]; dq.pop()
                    dq[-1] += te
                    if isvalid1(dq[-1]) is False:
                        err = True
                else:
                    err = True
            elif st[j][0] == 'SUB':
                if len(dq) > 1:
                    te = dq[-1]; dq.pop()
                    dq[-1] -= te
                    if isvalid1(dq[-1]) is False:
                        err = True
                else:
                    err = True
            elif st[j][0] == 'MUL':
                if len(dq) > 1:
                    te = dq[-1]; dq.pop()
                    dq[-1] *= te
                    if isvalid1(dq[-1]) is False:
                        err = True
                else:
                    err = True
            elif st[j][0] == 'DIV':#second // first
                if len(dq) > 1:
                    first = dq[-1]; dq.pop()
                    second = dq[-1]; dq.pop()

                    if first == 0:
                        err = True
                        break
                    if first > 0 and second < 0:# -13 // 4
                        dq.append(((-1)*second // first) * (-1)) # 13 // -4
                    elif first < 0 and second > 0:
                        dq.append((second // (first * -1)) * (-1))
                    else:
                        dq.append(second // first)
                else:
                    err = True
            elif st[j][0] == 'MOD':#second % first
                if len(dq) > 1:
                    first = dq[-1]; dq.pop()
                    second = dq[-1]; dq.pop()

                    if first == 0:
                        err = True
                        break
                    if first > 0 and second < 0:
                        dq.append(((-1)*second % first) * (-1))
                    elif first < 0 and second > 0:
                        dq.append(second % (-1 * first))
                    else:
                        dq.append(second % first)
                else:
                    err = True

            if err:
                break

        if err or len(dq) != 1:
            print('ERROR')
        else:
            print(dq[0])

    input() # 공백 처리용
    print()
