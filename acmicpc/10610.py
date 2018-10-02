n = sorted([int(i) for i in input()], reverse=True)

def sol():
    if n[-1] != 0 or sum(n) % 3 > 0:
        return -1
    return ''.join([str(i) for i in n])

print(sol())
