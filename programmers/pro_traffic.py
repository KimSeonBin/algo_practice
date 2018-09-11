def sou(lines):
    answer = 0
    start = []; end = []
    for item in lines:
        sitem = item.split(' ')
        sitem[2] = sitem[2][0:-1]
        nowtime = int(sitem[1][0:2])*3600000 + int(sitem[1][3:5])*60000 + int(sitem[1][6:8])*1000 + int(sitem[1][9::])

        addinfo1 = int(sitem[2][0]) * 1000
        addinfo2 = 0
        if len(sitem[2]) > 1:
            addinfo2 = int(sitem[2][2::])
            if len(sitem[2]) == 3:
                addinfo2 *= 100
            elif len(sitem[2]) == 4:
                addinfo2 *= 10

        starttime = nowtime - (addinfo1 + addinfo2 -1)
        end.append(nowtime)
        start.append(starttime)

    for i in range(0, len(start)):
        ss = start[i]; ee = end[i]
        temp = len(start); temp2 = len(start)
        for j in range(0, len(start)):
            if (ss + 1000 <= start[j]) or (ss > end[j]):
                temp -= 1
            if (ee + 1000 <= start[j]) or (ee > end[j]):
                temp2 -= 1

        if temp > answer:
            answer = temp
        if temp2 > answer:
            answer = temp2
    return answer


# print(sou(["2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:04.003 2.0s"]))
# print(sou(["2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"]))
# print(sou(["2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"]))
# print(sou(["2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"]))
