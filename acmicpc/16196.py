def sol():
    st = input()
    n = [st[0:6], st[6:14], st[14:17], st[17:18]]
    locate = []
    check = False
    for i in range(0, int(input())):
        if n[0] == input():
            check = True

    if check is False:
        return 'I'

    if n[2] == '000':
        return 'I'

    ndate = [n[1][0:4], n[1][4:6], n[1][6::]]
    if ndate[0] < '1900' or ndate[0] > '2011':
        return 'I'
    if ndate[1] < '01' or ndate[1] > '12':
        return 'I'

    year = int(ndate[0])
    month = int(ndate[1])
    day = int(ndate[2])
    if month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or \
    month == 10 or month == 12:
        if day < 1 or day > 31 or ndate[2] < '01' or ndate[2] > '31':
            return 'I'
    elif month == 2:
        yoon = False
        if year % 4 == 0:
            yoon = True
            if year % 100 == 0:
                yoon = False
            if year % 400 == 0:
                yoon = True
        if yoon is False:
            if day < 1 or day > 28 or ndate[2] < '01' or ndate[2] > '28':
                return 'I'
        else:
            if day < 1 or day > 29 or ndate[2] < '01' or ndate[2] > '29':
                return 'I'
    else:
        if day < 1 or day > 30 or ndate[2] < '01' or ndate[2] > '30':
            return 'I'

    temp = 2
    checksum = 0
    for i in range(1, len(st)):
        checksum += int(st[-1-i]) * temp
        temp *= 2
    if st[-1] == 'X':
        checksum += 10
    else:
        checksum += int(st[-1])

    if checksum % 11 != 1:
        return 'I'

    if int(n[2]) % 2 == 1:
        return 'M'
    else:
        return 'F'

if __name__ == '__main__':
    print(sol())
