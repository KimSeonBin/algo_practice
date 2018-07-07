t = int(input())

'''
http://jason9319.tistory.com/358
A, B 점을 가지는 선과 C, D 점을 가지는 선의 교차 여부

ccw(A,B,C)*ccw(A,B,D) <= 0 and ccw(C,D,A)*ccw(C,D,B) <= 0 이면 된다.
'''
def ccw(a, b, c):
    return (b[0] - a[0])*(c[1] - a[1]) - (b[1] - a[1])*(c[0] - a[0])

for iter in range(0, t):
    _ = input().split(' ')
    _ = [float(_[i]) for i in range(0, len(_))]
    xstart = _[0]; ystart = _[1]; xend = _[2]; yend = _[3]
    xleft = _[4]; ytop = _[5]; xright = _[6]; ybottom = _[7]
    recx = [xleft, xright]; recy = [ytop, ybottom]

    answer = False
    lineA = [xstart, ystart]; lineB = [xend, yend]
    lineA_ = sorted([lineA[0], lineB[0]]); lineB_ = sorted([lineA[1], lineB[1]])

    for i in range(0, 2):
        recA = [recx[i], recy[0]]
        recB = [recx[i], recy[1]]

        temp = ccw(lineA, lineB, recA) * ccw(lineA, lineB, recB)
        temp2 = ccw(recA, recB, lineA) * ccw(recA, recB, lineB)
        if temp <= 0 and temp2 <= 0:
            if temp == 0 and temp2 == 0:
                recx_ = sorted([recA[0], recB[0]])
                recy_ = sorted([recA[1], recB[1]])
                if lineA_[0] >= recx_[0] and lineA_[1] <= recx_[1]:
                    if lineB_[0] >= recy_[0] and lineB_[1] <= recy_[1]:
                        answer = True
            else:
                answer = True

        recA = [recx[0], recy[i]]
        recB = [recx[1], recy[i]]

        temp = ccw(lineA, lineB, recA) * ccw(lineA, lineB, recB)
        temp2 = ccw(recA, recB, lineA) * ccw(recA, recB, lineB)
        if temp <= 0 and temp2 <= 0:
            if temp == 0 and temp2 == 0:
                recx_ = sorted([recA[0], recB[0]])
                recy_ = sorted([recA[1], recB[1]])
                if lineA_[0] >= recx_[0] and lineA_[1] <= recx_[1]:
                    if lineB_[0] >= recy_[0] and lineB_[1] <= recy_[1]:
                        answer = True
            else:
                answer = True
    #
    # recA = [recx[1], recy[0]]
    # recB = [recx[0], recy[1]]
    #
    # temp = ccw(lineA, lineB, recA) * ccw(lineA, lineB, recB)
    # temp2 = ccw(recA, recB, lineA) * ccw(recA, recB, lineB)
    # if temp <= 0 and temp2 <= 0:
    #     if temp == 0 and temp2 == 0:
    #         recx_ = sorted([recA[0], recB[0]])
    #         recy_ = sorted([recA[1], recB[1]])
    #         if lineA_[0] >= recx_[0] and lineA_[1] <= recx_[1]:
    #             if lineB_[0] >= recy_[0] and lineB_[1] <= recy_[1]:
    #                 answer = True
    #     else:
    #         answer = True

    if answer:
        print('T')
    else:
        print('F')
