
num = input()
drink = []

for i in range(int(num)):
	drink.append(int(input()))

def acmicpc2156(num):
	mm = []
	num = int(num)

	if num == 1:
		print(drink[0])
		return
	mm.append(drink[0])

	if num == 2:
		print(drink[0]+drink[1])
		return
	mm.append(sum(drink[0:2]))

	if num == 3:
		print(max(drink[1]+drink[0], max(drink[2]+mm[0], drink[2]+drink[1])))
		return
	mm.append(max(drink[2]+mm[0], drink[2]+drink[1]))
	if num == 4:
		print(max(drink[3]+mm[1], drink[3]+drink[2]+mm[0]))
		return
	mm.append(max(drink[3]+mm[1], drink[3]+drink[2]+mm[0]))

	for i in range(5, num+1):
		mm.append(max(drink[i-1]+drink[i-2]+mm[i-5], max(drink[i-1]+mm[i-3], drink[i-1]+drink[i-2]+mm[i-4])))
	print(max(mm))
	return

acmicpc2156(num)