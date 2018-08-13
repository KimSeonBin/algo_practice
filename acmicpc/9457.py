t = int(input())
modul = 10007

square = [1, 4, 15]
circle = [1, 12, 75]#384
circlet = [0, 1, 6, 25]

for i in range(3, 50001):
    square.append((square[i-1] * 4 - square[i-2]) % modul)
    circlet.append((circlet[-1]*5 - circlet[-2]*5 + circlet[-3]) % modul)
    circle.append((circlet[-1] * (i+1)) % modul)
for iter in range(0, t):
    n = int(input())
    print(str(square[n-1]) + ' ' + str(circle[n-1]))
