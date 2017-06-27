#codingdojang.com 134번 문제
fibonacci = [1,2]
a=0; b=1; c=0

while(1):
	c = fibonacci[a] + fibonacci[b]
	if c < 4000000 : 
		fibonacci.append(c)
		a+=1; b+=1;
	else :
		break
#홀수 + 짝수 = 홀수, 짝수 + 홀수 = 홀수, 홀수 + 홀수 = 짝수, 홀수 + 짝수 = 홀수.
#이런 순서로 나아가므로 짝수는 1, 4, 7, ... 와 같이 이루어져있다.
b=1; c=0
while(b < len(fibonacci)):
	c+=fibonacci[b]
	b+=3

print(c)
