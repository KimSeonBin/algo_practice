from collections import deque

'''
ex1)
3 5
b c d o u
'''
q = deque()
L, c = map(int, input().split(' '))
sen = list(input().split(' '))
sen = sorted(sen)
aeiou = ['a', 'e', 'i', 'o', 'u']

def recur(index):
    if len(q) == L:
        temp = 0; temp2 = 0
        for item in q:
            if item in aeiou:
                temp += 1
            else:
                temp2 += 1
        if temp > 0 and temp2 > 1:
            for item in q:
                print(item, end='')
            print('')
        return

    for i in range(index, c):
        q.append(sen[i])
        recur(i+1)
        q.pop()

for i in range(0, c):
    q.append(sen[i])
    recur(i+1)
    while len(q) != 0:
        q.pop()
