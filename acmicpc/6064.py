t = int(input())

def gcd(m, n):
    while m % n != 0:
        temp = m % n
        m = n
        n = temp
    return n

for iteration in range(0, t):
    m, n, x, y = input().split(' ')
    m = int(m); n = int(n); x = int(x); y = int(y);
    tx = x
    lcm_mn = m * n // gcd(m, n)
    while True:
        txn = tx % n
        if txn == 0:
            txn = n
        if txn == y:
            print(tx)
            break
        if tx < lcm_mn:
            tx += m
        else:
            print(-1)
            break
