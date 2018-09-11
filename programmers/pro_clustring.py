

def solution(str1, str2):
    answer = 0
    str1c = []; str2c = []
    str1 = str1.lower(); str2 = str2.lower();

    for i in range(0, len(str1)-1):
        sen = str1[i:i+2]
        if ord(sen[0]) >= 97 and ord(sen[0]) <= 122 and ord(sen[1]) >= 97 and ord(sen[1]) <= 122:
            str1c.append(sen)
    for i in range(0, len(str2)-1):
        sen = str2[i:i+2]
        if ord(sen[0]) >= 97 and ord(sen[0]) <= 122 and ord(sen[1]) >= 97 and ord(sen[1]) <= 122:
            str2c.append(sen)

    if len(str1c) == 0 and len(str2c) == 0:
        return 65536


    addstr = []; mulstr = []
    sc1 = [False] * len(str1c); sc2 = [False] * len(str2c)
    for i in range(0, len(str1c)):
        sc1[i] = True
        addstr.append(str1c[i])
        for j in range(0, len(str2c)):
            if str1c[i] == str2c[j] and sc2[j] == False:
                sc2[j] = True
                break

    for i in range(0, len(sc1)):
        if sc1[i] == False:
            addstr.append(str1c[i])
    for i in range(0, len(sc2)):
        if sc2[i] == False:
            addstr.append(str2c[i])

    sc2 = [False] * len(str2c)
    for i in range(0, len(str1c)):
        for j in range(0, len(str2c)):
            if str1c[i] == str2c[j] and sc2[j] == False:
                mulstr.append(j)
                sc2[j] = True
                break

    addstr = len(addstr)
    mulstr = len(mulstr)

    answer = (mulstr * 65536) // addstr

    return answer
