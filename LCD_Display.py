num='123456789'; count='2'
num=int(num); count=int(count)

def first_part(num, count) :
	print(' ', end='')
	if num == 1 or num == 4:
		while count > 0 :
			print(' ', end='')
			count -= 1
	else :
		while count > 0 :
			print('-', end='')
			count -= 1
	print('  ', end='')
def second_part(num, count) :
	if num == 1 or num == 2 or num == 3 or num == 7 :
		while count > 1 :
			print(' ', end='')
			count -= 1
		print('|', end='')
	elif num == 5 or num == 6 :
		print('|', end='')
		while count > 1 :
			print(' ', end='')
			count -= 1
	else :
		print('|', end='')
		while count > 2 :
			print(' ', end='')
			count -= 1
		print('|', end='')
	print(' ', end='')
def third_part(num, count) :
	print(' ', end='')
	if num == 1 or num == 7 or num == 0 :
		while count > 0 :
			print(' ', end='')
			count -= 1
	else :
		while count > 0 :
			print('-', end='')
			count -= 1
	print('  ', end='')
def fourth_part(num, count) :
	if num == 1 or num == 3 or num == 4 or num == 5 or num == 7 or num == 9:
		while count > 1 :
			print(' ', end='')
			count -= 1
		print('|', end='')
	else :
		print('|', end='')
		while count > 2 :
			print(' ', end='')
			count -= 1
		print('|', end='')
	print(' ', end='')
def fifth_part(num, count) :
	print(' ', end='')
	if num == 1 or num == 4 or num == 7:
		while count > 0 :
			print(' ', end='')
			count -= 1
	else :
		while count > 0 :
			print('-', end='')
			count -= 1
	print('  ', end='')
def print_digit(num, count) :
	numlist=[]
	while num > 0 :
		numlist.append(num % 10)
		num /= 10
		num = int(num)
	numlist.reverse()
	print(numlist)
	for j in numlist :
		first_part(j, count)
	print('')
	i = 0
	while i < count :
		for j in numlist :
			second_part(j, count+2)
		print('')
		i += 1
	for j in numlist :
		third_part(j, count)
	print('')
	i = 0
	while i < count :
		for j in numlist :
			fourth_part(j, count+2)
		print('')
		i += 1
	for j in numlist :
		fifth_part(j, count)
	print('')
print_digit(num, count)