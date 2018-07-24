'''
3
short
lines?
sldkfjlsdkjflsjflsejlfkjselfkj
31

4
A AA
AA A
A A
A
4
'''

import re
while True:
    n = int(input())
    if n == 0:
        break
    sen = [input() for i in range(0, n)]
    reg = ' '
    p = re.compile(reg)
    start = 0

    for i in range(0, n):
        result = p.finditer(sen[i])
        check = True
        for refor in result:
            if start <= refor.start():
                start = refor.start()
                check = False
                break
        if check is True and start <= len(sen[i]):
            start = len(sen[i])
    print(start+1)
