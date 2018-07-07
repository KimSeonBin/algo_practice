a = input()
b = a.split(' ')

b[0] = int(b[0][::-1])
b[1] = int(b[1][::-1])
print(max(b))