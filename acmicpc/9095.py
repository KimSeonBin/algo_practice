n = int(input())
answer = []
answer.append(1)
answer.append(2)
answer.append(4)
answer.append(7)
answer.append(13)

for i in range(5, 10):
    answer.append(answer[-1]+answer[-2]+answer[-3])
#?6 : 24
#?7 : 44
#?8 : 81
#?9 : 149
#?10: 274


#7: 44
#10: 274

for i in range(0, n):
    index = int(input())
    print(answer[index-1])
