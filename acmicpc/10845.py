import queue

q = queue.Queue()
qtemp = []
t = int(input())

for iter in range(0, t):
    command = input()
    qlen = q.qsize()

    if command == 'size':
        print(q.qsize())
    elif command == 'empty':
        check = q.empty()
        if check is True:
            print(1)
        else:
            print(0)
    elif command == 'front':
        if qlen != 0:
            print(qtemp[0])
        else:
            print(-1)
    elif command == 'back':
        if qlen != 0:
            print(qtemp[-1])
        else:
            print(-1)
    elif command == 'pop':
        if qlen != 0:
            print(q.get())
            qtemp.pop(0)
        else:
            print(-1)
    else:
        command, num = command.split()
        num = int(num)
        q.put(num)
        qtemp.append(num)
