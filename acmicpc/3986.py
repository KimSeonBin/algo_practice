n = int(input())
answer = 0
for iter in range(0, n):
    sen = input()
    stack = []
    senlen = len(sen)
    for i in range(0, senlen):
        if len(stack) == 0:
            stack.append(sen[i])
            continue
        if stack[-1] == sen[i]:
            stack.pop()
        else:
            stack.append(sen[i])

    if(len(stack) == 0):
        answer += 1
print(answer)
