#http://joonas.tistory.com/25
'''
확장 유클리드 호제법
ax + by = 1가 있을 때 x, y의 정수해 s, t를 찾는방법
s0 = 1, s1 = 0
t0 = 0, t1 = 1
r0 = a, r1 = b

qi = ri-1 // ri
si = si-2 - (si-1 * qi)
ti = ti-2 - (ti-1 * qi)
ri = ri-2 - (ri-1 * qi)
위의 계산식을 ri가 0이 될 때까지 반복한다.
뒤에서 2번째 값이 정수해 s, t이다.

'''
t = int(input())
limit = 1000000000

def gcd(m, n):
    while m % n != 0:
        temp = m % n
        m = n
        n = temp
    return n

for iteration in range(0, t):
    k, c = input().split(' ')
    k = int(k); c = int(c)

    if c == 1:
        if k+1 > limit:
            print('IMPOSSIBLE')
            continue
        print(k+1)
        continue
    if k == 1:
        print(1)
        continue

    kc = gcd(k, c)
    if kc is not 1:
        print('IMPOSSIBLE')
        continue

    s = [1, 0]; t = [0, 1]; r = [k*-1, c]; q = 0

    while r[-1] != 0:
        q = r[-2] // r[-1]
        t.append(t[-2] - (t[-1] * q))
        s.append(s[-2] - (s[-1] * q))
        r.append(r[-2] - (r[-1] * q))
    while t[-2] < 0:
        t[-2] += k
    if t[-2] > limit:
        print('IMPOSSIBLE')
    else:
        print(t[-2])
