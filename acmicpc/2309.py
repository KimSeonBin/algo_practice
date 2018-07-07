nanjang = 9
ki = []
for i in range(0, nanjang):
    ki.append(int(input()))
ki = sorted(ki)
answer = []
total = 0; total_nan = 100

def recur(index):
    global total
    if len(answer) == 7 and total == total_nan:
        return True
    elif len(answer) == 7 and total != total_nan:
        return False

    for i in range(index+1, nanjang):
        if total_nan == total + ki[i]:
            answer.append(ki[i])
            total += ki[i]
            return True
        elif total_nan >= total + ki[i]:
            answer.append(ki[i])
            total += ki[i]
            if recur(i):
                return True
            else:
                total -= ki[i]
                answer.pop()
                continue
        else:
            #answer.pop()
            break
    return False

for index in range(0, nanjang - 2):
    answer.append(ki[index])
    total += ki[index]
    if recur(index):
        break
    answer.pop()
    total -= ki[index]
for item in answer:
    print(item)
