import heapq

def solution(arguments):
    answer = []
    minheap = []; maxheap = [];
    minoper = 0; maxoper = 0;
    check = [False] * 1000000; index = 0

    for item in arguments:
        num = int(item[2:])
        if item[0] == 'I':
            heapq.heappush(minheap, (num, index))
            heapq.heappush(maxheap, (num*(-1), index))
            answer.append(num)
            index += 1
        else:
            if minoper >= len(answer) - maxoper:
                continue
            if num == 1:
                while(True):
                    t = heapq.heappop(maxheap)
                    if check[t[1]] == False:
                        check[t[1]] = True
                        break
                maxoper += 1
            else:
                while(True):
                    t = heapq.heappop(minheap)
                    if check[t[1]] == False:
                        check[t[1]] = True
                        break
                minoper += 1

    if minoper >= len(answer) - maxoper:
        answer = [0, 0]
    else:
        temp = []
        for i in range(0, len(answer)):
            if check[i] == False:
                temp.append(answer[i])

        if len(answer) - maxoper - minoper > 1:
            answer = [max(temp), min(temp)]
        else:
            answer = [temp[0], temp[0]]
    return answer
