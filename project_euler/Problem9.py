#프로젝트 오일러 9번문제
#http://euler.synap.co.kr/prob_detail.php?id=9
#a는 최소 1, 최대 1000/3 -> 333에서 1을 뺀 332까지의 값까지 가질수 있고
#b는 최소 2, 최대 (1000-1)/2 -> 498까지의 숫자를 가질 수 있습니다.
#이를 이용해 범위를 줄여 계산했습니다.
import sys
a = 0; b = 0; c = 0 
for a in range(1, 332) :
	ran = int((1000-a)/2)
	for b in range(1+a, ran) :
		c = 1000 - a - b
		if (pow(a, 2) + pow(b, 2)) == pow(c, 2) :
			print(a*b*c)
			print(a,b,c)
			sys.exit()