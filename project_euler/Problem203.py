import math

i = 1
Total_Pascal = []

def contain(value) :
	if value in Total_Pascal :
		return True
	else :
		return False
def nCr(n,r) :
	f = math.factorial
	return int(int(f(n) // f(r)) // f(n-r))
def squarefree(value) :
	k = 2
	while k * k <= value :
		if value % (k*k) == 0 :
			return False
		k += 1
	return True

while i < 51 :
	Pascal = []
	temp = i
	while temp > 0 :
		Pascal.append(nCr(i, temp))	
		temp -= 1
	print(Pascal)
	for j in Pascal :
		if contain(j) :
			continue
		else :
			if squarefree(j) :
				Total_Pascal.append(j)

	i += 1
Total_Pascal.sort()
print(Total_Pascal)
print(sum(Total_Pascal))