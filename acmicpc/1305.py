'''
aabaa

pi  0 1 0 1 2

Pi[N] : 처음 위치부터 현재까지 잘 맞춰져 온 문자 길이 라고 이해하시면

N-Pi[N-1] : 최대가 N이고 잘 맞춰져 온 거리 만큼 빼주면 그 나머지가 답이 될수 있는 가장 짧은 길이라고 판단됩니다.

마지막 pi의 값은 L의 prefix와 suffix가 일치하는 길이이다.
prefix와 suffix가 일치하지 않는 부분 'b'가 있다.
즉 'aa' + 'b' + 'aa' + 'b' + 'aa' + 'b' + 'aa' ....이런식으로 반복된다.
따라서 답은 pi[n-1] + 일치하지 않는 부분의 길이 = N - pi[n-1]
'''

l = int(input())
sen = input()
answer = 0

pi = [0 for i in range(0, l)]
temp = 0
for i in range(1, l):
    while temp != 0 and sen[temp] != sen[i]:
        temp = pi[temp - 1]
    if sen[temp] == sen[i]:
        temp += 1
        pi[i] = temp
answer = l - pi[l-1]
print(pi)
print(answer)
