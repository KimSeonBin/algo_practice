a, b = input().split(' ')
lena = len(a)-1; lenb = len(b)-1; lenab = 0
tempa = 0; tempb = 0
moreadd = 0
answer = ''

if lena < lenb:
    lenab = lenb
else:
    lenab = lena

for i in range(0, lenab+1):
    if lena - i >= 0:
        tempa = a[lena-i]
    else:
        tempa = 0
    if lenb - i >= 0:
        tempb = b[lenb-i]
    else:
        tempb = 0
    temp = int(tempa) + int(tempb) + moreadd
    answer = str(temp % 10) + answer
    moreadd = temp // 10
if moreadd != 0:
    answer = str(moreadd) + answer
print(answer)
