def solution(n, t, m, timetable):
    answer = 0
    timetable = [int(item[0:2])*60 + int(item[3::]) for item in timetable]
    check = [False] * len(timetable)
    timetable.sort()

    div = []
    for i in range(0, n):
        now = 540 + i*t
        temp = []
        for j in range(0, len(timetable)):
            if check[j] == False and now >= timetable[j]:
                temp.append(timetable[j])
                check[j] = True
            if len(temp) == m:
                break
        div.append(temp)

    temp = div[n-1]
    if len(temp) < m:
        answer = 540 + (n-1)*t
    elif len(temp) == m:
        last = -1
        if m == 1:
            last = temp[0]-1
        else:
            for i in range(0, len(temp)-1):
                if temp[i] != temp[i+1]:
                    last = temp[i+1]-1
            if last == -1:
                last = temp[0]-1
        answer = last


    answer = '{0:02}:{1:02}'.format(answer // 60, answer % 60)

    return answer
