import functools
#
ori = input(); orilen = len(ori)
pos = [ord(ori[i]) for i in range(0, orilen)]
suffix = [i for i in range(0, orilen)]
d = 1

def cmpto(i, j):
    if pos[i] != pos[j]:
        return pos[i] < pos[j]
    i += d; j += d
    if i < orilen and j < orilen:
        return pos[i] < pos[j]
    else:
        return i > j

while True:
    #suffix = sorted(suffix, cmp=cmpto)
    suffix = sorted(suffix, key=functools.cmp_to_key(cmpto))
    temp = [0 for i in range(0, orilen)]
    for i in range(0, orilen-1):
        temp[i+1] = temp[i] + cmpto(suffix[i], suffix[i+1])
    for i in range(0, orilen):
        pos[suffix[i]] = temp[i]
    if temp[orilen-1] == orilen-1:
        break

    d *= 2

# LCP algorithm
rank = [0 for i in range(0, orilen)]
lcd = [0 for i in range(0, orilen)]
llen = 0
for i in range(0, orilen):
    rank[suffix[i]-1] = i

for i in range(0, orilen):
    k = rank[i]
    if k > 0:
        j = suffix[k-1] - 1
        while ori[j+llen] is ori[i+llen]:
            if j + llen + 1 >= orilen or i + llen + 1 >= orilen:
                lcd[k] = llen+1
                break
            llen+=1
            lcd[k] = llen

        if llen > 0:
            llen -= 1

print('x ', end='')
for i in range(1, orilen):
    print(lcd[i], end=' ')
