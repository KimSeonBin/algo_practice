def solution(citations):
    answer = 0
    citations.sort()

    for i in range(0, 1001):
        temp2 = 0
        for item in citations:
            if i <= item: # h번 이상 인용
                temp2 += 1

        if temp2 >= i:
            answer = i

    return answer
