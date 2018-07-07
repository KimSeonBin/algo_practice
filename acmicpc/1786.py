t = input(); p = input()
t_len = len(t); p_len = len(p)
pi = [0 for i in range(0, p_len)]
founded_count = 0; founded_location = []

#pi array
temp = 0
for i in range(1, p_len):
    while temp > 0 and p[i] != p[temp]:
        temp = pi[temp - 1]
    if p[i] == p[temp]:
        temp += 1
        pi[i] = temp

#kmp algorithm
temp = 0
for i in range(0, t_len):
    while temp > 0 and t[i] != p[temp]:
        temp = pi[temp-1]
    if t[i] == p[temp]:
        if temp == p_len-1:
            founded_count+=1
            founded_location.append(i-(temp-1))
            temp = pi[temp]
        else:
            temp += 1

print(founded_count)
for i in range(0, len(founded_location)):
    print(founded_location[i], end=' ')
