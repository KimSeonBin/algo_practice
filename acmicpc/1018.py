m, n = map(int, input().split(' '))
board = [input() for i in range(0, m)]

answer = 400000

for i in range(0, m-7):
    for j in range(0, n-7):
        check = 0
        firstb = board[i][j]
        # board check
        for a in range(0, 8):
            for b in range(0, 4):
                if a % 2 == 0:
                    if firstb != board[i + a][j + 2*b]:#(0,0)(0,2)(2,0)... 같아야함
                        check += 1
                    if firstb == board[i + a][j + 2*b + 1]:#(0,1)(0,3)(1,3)... 달라야함
                        check += 1
                else:
                    if firstb != board[i + a][j + 2*b+1]:#(1,1)(3,3)(3,5)... 같아야함
                        check += 1
                    if firstb == board[i + a][j + 2*b]:#(1,2)(1,4)(3,2)... 달라야함
                        check += 1
        check = min([check, 64-check])
        answer = min([answer, check])

print(answer)
