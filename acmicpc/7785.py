n = int(input())

log = {}
for _ in range(n):
    st = input().split()

    if st[1] == 'enter':
        log[st[0]] = 1
    else:
        del(log[st[0]])

peo = list(log.keys())
peo.sort()

for i in range(0, len(peo)):
    print(peo[-1-i])
