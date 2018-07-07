m = int(input())
answer = 0; moduler = 1000000007
tn = 1; ts = 0
for iter in range(0, m):
    n, s = input().split(' ')
    n = int(n); s = int(s)

    gcdnn = 1
    tmpts = n; tmptn = tn
    while tmptn % tmpts != 0:
        temp = tmptn % tmpts
        tmptn = tmpts
        tmpts = temp
    gcdnn = tmpts

    ts = (ts * (n // gcdnn)) + (s * (tn // gcdnn))
    tn = tn * n // gcdnn

a = [1, 0]
b = [0, 1]
r = [moduler, tn]
q = 0
while r[-1] % r[-2] != 0:
    q = r[-2] // r[-1]
    a.append(a[-2] - (a[-1] * q))
    b.append(b[-2] - (b[-1] * q))
    r.append(r[-2] - (r[-1] * q))

if b[-2] < 0:
    b[-2] += moduler
answer += (ts * b[-2]) % moduler
print(answer)
