n = int(input())
med = []	#약 효험
med_index = []#약 이름

for i in range(n):
	temp = input()
	temp = temp.split(' ')
	med.append(temp[0])
	med_index.append(temp[1])

r = int(input())
for i in range(r):
	dis = []

	temp = input()
	temp = temp.split(' ')
	length = int(temp[0])
	dis.append(temp[1:])

	index = []

	for j in range(length):
		temp2 = med.index(dis[0][j]) if dis[0][j] in med else -1
		index.append(temp2)

	temp3 = index.index(-1) if -1 in index else -1
	if temp3 == -1:
		for j in range(len(index)):
			print(med_index[index[j]], end=' ')
	else :
		print('YOU DIED', end='')
	print()

