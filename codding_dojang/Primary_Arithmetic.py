#코딩도장 11번 문제

def result(up) :
	if up != 0 : 
		print('{0} carry operartion'.format(up))
	else :
		print('No carry operation')

#뒤에서부터 한 숫자씩 계산을 하면서 10이 넘어가면 count += 1을 해줘
#올림연산을 했다는 것을 알려줍니다.
def proc() :
	num1 = '525'; num2 = '55555'
	count = 0; up = 0; i =0
	while i < len(num1) and i < len(num2) :
		temp = int(num1[len(num1)-i-1]) + int(num2[len(num2)-i-1]) + count
		if temp >= 10 :
			count += 1; up += 1
		else :
			count = 0
		i += 1
	return up

res = proc(); result(res)