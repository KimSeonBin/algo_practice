from collections import deque

ss =  deque(); answerstack = deque()
answer = 0; temp = 0
sen = input()

for item in sen:
    if item == '(':
        ss.append(0)
    else:
        num = ss.pop()
        if len(ss) == 0:
            answer += num
        else:
            if num == 0:
                num += 1
                ss.append(num)
            else:
                while ss[-1] != 0:
                    temp = ss.pop()
                    num += temp
                if len(ss) != 0:
                    ss.pop()
                ss.append(num)
                answer += (num + 1)

print(answer)
