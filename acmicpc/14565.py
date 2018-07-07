#http://joonas.tistory.com/25

n, a = input().split(' ')
n = int(n); a = int(a)

replus = n - a
remul = -1

#gcd
tn = n; ta = a
while tn % ta != 0:
    temp = tn % ta
    tn = ta
    ta = temp

if ta != 1:
    print(str(replus) + ' ' + str(remul))
    exit()

s = [1, 0]
t = [0, 1]
r = [n, -1 * a]
q = 0

while r[-2] % r[-1] != 0:
    q = r[-2] // r[-1]
    s.append(s[-2] - (s[-1] * q))
    t.append(t[-2] - (t[-1] * q))
    r.append(r[-2] - (r[-1] * q))

while t[-1] < 0:
    t[-1] += n
remul = t[-1]

print(str(replus) + ' ' + str(remul))
