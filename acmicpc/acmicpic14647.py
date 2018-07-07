input_nm = input()
input_nm = input_nm.split(' ')
nm = []
xy = []
xy9_count = []
total = 0

for i in range(int(input_nm[0])):
	nm = input()
	nm = nm.split(' ')
	xy.append(nm)

for i in range(int(input_nm[0])):
	temp = 0
	for j in range(int(input_nm[1])):
		a = xy[i][j].count('9')
		if a != -1 :
			temp = temp + a
	xy9_count.append(temp)

total = sum(xy9_count)

for i in range(int(input_nm[1])):
	temp = 0
	for j in range(int(input_nm[0])):
		a = xy[j][i].count('9')
		if a != -1 :
			temp = temp + a
	xy9_count.append(temp)

print(total - max(xy9_count))