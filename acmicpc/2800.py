st = input()
bracket = []
answer = []

def get_all_bracket():
    for i in range(0, len(st)):
        if st[i] == '(':
            bracket.append([i, -1])
        elif st[i] == ')':
            index = len(bracket)-1

            while index >= 0:
                if bracket[index][1] == -1:
                    bracket[index][1] = i
                    break
                index -= 1

def backtracking(index, ori):
    for i in range(index+1, len(bracket)):
        temp = ori[0: bracket[i][0]] + ' ' + ori[bracket[i][0]+1: bracket[i][1]] + ' ' + ori[bracket[i][1]+1::]
        backtracking(i, temp)
        answer.append(temp.replace(' ', ''))

def print_answer():
    answer2 = list(set(answer))
    answer2.sort()
    for item in answer2:
        print(item)

get_all_bracket()
backtracking(-1, st)
print_answer()
