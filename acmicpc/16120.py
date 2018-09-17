'''
P
PPAP
PPAPPAP PPPAPAP PPAPPAP

PPAP 문자열이 되기 위해선 A 문자가 올 때 앞의 P의 개수가 2개 이상이어야 하고
뒤에 P의 개수가 1개 이상이어야 한다.
또한 모든 PPAP를 P로 변환 후 P 1개만 남아있는 상태여야 하니 p_count == 1이면 PPAP 문자열
'''

sen = input().strip()
p_count = 0
isanswer = True

if len(sen) % 3 != 1:
    isanswer = False

for i in range(0, len(sen)):
    if sen[i] == 'P':
        p_count += 1
    else:
        if i+1 == len(sen):
            isanswer = False
            break
        if p_count > 1 and sen[i+1] == 'P':
            p_count -= 2
        else:
            isanswer = False
            break
if p_count != 1:
    isanswer = False

if isanswer is False:
    print('NP')
else:
    print('PPAP')
