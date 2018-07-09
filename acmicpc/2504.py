from collections import deque
q = deque()
sen = input()
answer = 0; check = True

for item in sen:
    if check == False:
        break
    if len(q) == 0:
        q.append(item)
        continue
    if item == '(' or item == '[':
        q.append(item)
    if item == ')':
        temp = q.pop(); tempanswer = 0
        if temp == '(':
            tempanswer = 1
        while temp != '(':
            if temp == '[' or temp == ']' or temp == ')':
                check = False
                q.append('[')
                break
            tempanswer += temp
            if len(q) != 0:
                temp = q.pop()
            else:
                check = False
                q.append('(')
                break
        q.append(tempanswer * 2)
    if item == ']':
        temp = q.pop(); tempanswer = 0
        if temp == '[':
            tempanswer = 1
        while temp != '[':
            if temp == '(' or temp == ')' or temp == ']':
                check = False
                q.append('[')
                break
            tempanswer += temp
            if len(q) != 0:
                temp = q.pop()
            else:
                check = False
                q.append('[')
                break
        q.append(tempanswer * 3)

checklist = ['(', ')', '[', ']']
for item in q:
    if item in checklist:
        answer = 0
        break
    answer += item
print(answer)
