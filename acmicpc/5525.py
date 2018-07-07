n = int(input())
pn = 'I'
for i in range(0, n):
    pn += 'OI'
m = int(input())
s = input()
total_count = 0

temp = 0
p_len = len(pn)
pi = [0 for i in range(0, p_len)]
#pi array
for i in range(1, p_len):
    while temp > 0 and pn[i] != pn[temp]:
        temp = pi[temp-1]
    if pn[i] == pn[temp]:
        temp += 1
        pi[i] = temp
#kmp
temp = 0
for i in range(0, m):
    while temp > 0 and s[i] != pn[temp]:
        temp = pi[temp-1]
    if s[i] == pn[temp]:
        if temp == p_len-1:
            total_count += 1
            temp = pi[temp]
        else:
            temp += 1
print(total_count)
