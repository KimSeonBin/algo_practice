import collections


def sol():
    str = input()
    dqleft = collections.deque()
    dqright = collections.deque()

    for word in str:
        if word == '<':
            if len(dqleft) > 0:
                dqright.append(dqleft.pop())
        elif word == '>':
            if len(dqright) > 0:
                dqleft.append(dqright.pop())
        elif word == '-':
            if len(dqleft) > 0:
                dqleft.pop()
        else:
            dqleft.append(word)

    for i in dqleft:
        print(i, end='')
    while len(dqright) > 0:
        print(dqright.pop(), end='')
    print()

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        sol()
