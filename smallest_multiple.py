#codingdojang.com 132번 문제.
primenumber = [2]
interval = 20; temp = 3

#20까지의 소수를 구합니다.
while(temp < interval) : 
	if temp % 2 == 0 : #2의 배수는 생각할 필요도 없이 pass
		temp = temp + 1
		continue
	for i in primenumber : #list내의 소수와 비교해서 나누어 떨어진다면 not 소수
		if temp % i == 0 :
			break
		elif i == primenumber[len(primenumber) - 1]:
			primenumber.append(temp)
	temp = temp + 1


#소수별로 20을 넘지않는 제곱수를 구합니다.
#예를 들어서 2는 16, 3은 9, 5는 5, ... 이런식으로 다 구해서
#곱한 수가 1~20사이의 어떤 수로도 나누어 떨어지는 가장 작은 수입니다.
result = 1
for i in primenumber :
	while(1) :
		if i * i < interval :
			i = i * i
		else :
			result = result * i
			break
print(result)