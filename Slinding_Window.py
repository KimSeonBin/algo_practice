import random
import bisect

size = 1000000; count = 1000; i = 0

sor_win = []
window = []
max_val = []; min_val = []

while i < size :
	window.append(random.randrange(-10000,10001))
	i+=1

'''
첫번째 방법 : 75초정도
i = 0
while i < size - count + 1 :
	max_val.append(max(window[i:i+count]))
	min_val.append(min(window[i:i+count]))
	i += 1
'''

'''
두번째 방법 31.0초정도
Onkel님의 설명을 보고 단순한 반복문으로 만들어 봤습니다.
window만 따로 뽑아서 list를 구성 후 sort.
max value, min value를 뽑고 window를 이동시키며 빼야할 value를 찾아
sor_win에서 index를 찾아 새로 합류할 value로 변경합니다.
그 후 sort부터 반복
'''
'''
i = 0
#sor_win = window[0:count-1]
sor_win = window[0:count];
while i < size - count:
	sor_win.sort();

	max_val.append(sor_win[count-1])
	min_val.append(sor_win[0])

	index = sor_win.index(window[i]);
	
	sor_win[index] = window[count+i];i+=1

#마지막 sort가 위의 반복문에서 포함되지 않길래 추가했습니다.......
sor_win.sort();
max_val.append(sor_win[count-1])
min_val.append(sor_win[0])
'''

'''
3번째 방법 22초 정도
2번째 방법에서 sort방법을 bisect을 추가했습니다.
풀이를 보고 bisect을 넣으면 더 빨라진다길래 넣어봤는데 확실히 더 빨라지네요
'''

i = 0

sor_win = window[0:count]
sor_win.sort()
while i < size - count:
	max_val.append(sor_win[count-1])
	min_val.append(sor_win[0])

	index = sor_win.index(window[i]);
	sor_win.remove(sor_win[index])
	bisect.insort(sor_win, window[count+i])
	
	i+=1

max_val.append(sor_win[count-1])
min_val.append(sor_win[0])

#print(window)
print(max_val)
print(min_val)
