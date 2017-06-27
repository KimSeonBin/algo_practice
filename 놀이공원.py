#코딩도장 135번 문제
import random

matrix = ['GO', 'A1', 'CC1', 'A2', 'T1', 'R1', 'B1', 'CH1', 'B2', 'B3', 'JAIL', 'C1', 'U1', 'C2', 'C3', 'R2', 'D1', 'CC2', 'D2', 'D3', 'FP', 'E1', 'CH2', 'E2', 'E3', 'R3', 'F1', 'F2', 'U2', 'F3', 'G2J', 'G1', 'G2', 'CC3', 'G3', 'R4', 'CH3', 'H1', 'T2', 'H2']
matrix_count=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
card_CH = ['GO', 'JAIL', 'C1', 'E3', 'H2', 'R1', 'R', 'R', 'U', '-3', 'Bomb', 'Bomb', 'Bomb', 'Bomb', 'Bomb', 'Bomb']
card_CC = ['GO', 'JAIL', 'Bomb', 'Bomb', 'Bomb', 'Bomb', 'Bomb', 'Bomb', 'Bomb', 'Bomb', 'Bomb', 'Bomb', 'Bomb', 'Bomb', 'Bomb', 'Bomb']
R = []; U = []
i = 0; dice = 0; dice2 = 0
pos = 0; double_count = 0
matrix_size = len(matrix)

def throw_dice() :
	return random.randrange(1, 5)
def init_card() :
	random.shuffle(card_CH)
	random.shuffle(card_CC)
def draw_card_CH() :
	temp = card_CH.pop()
	card_CH.insert(0, temp)
	return temp
def draw_card_CC() :
	temp = card_CC.pop()
	card_CC.insert(0, temp)
	return temp

#CC?, CH?를 구분하기 위해 만들었던 함수.
#겸사겸사 G2J도 넣어 G2J 처리를 용이하게 할려고 끼어 넣었습니다.
def check_where(position) :
	if position.find('CC') != -1 :
		return 'CC'
	elif position.find('CH') != -1 :
		return 'CH'
	elif position.find('G2J') != -1 :
		return 'G2J'
	else :
		return 'ANY'

#R과 U의 위치를 미리 파악한 후 다음 R, U의 위치를 빠르게 찾게 하기위해
#만들었습니다.(찬스카드 다음 R or U 로 이동하시오.)
def where_R() :
	i = 0
	while i < len(matrix):
		if matrix[i].find('R') != -1 :
			R.append(i)
		i += 1
def where_U() :
	i = 0
	while i < len(matrix):
		if matrix[i].find('U') != -1 :
			U.append(i)
		i += 1
def next_R(pos) :
	i = 0
	while i < (len(R)-1) :
		if R[i] < pos < R[i+1] :
			return R[i+1]
		i += 1
	else :
		return R[0]
def next_U(pos) :
	i = 0
	while i < (len(U)-1) :
		if U[i] < pos < U[i+1] :
			return U[i+1]
		i += 1
	else :
		return U[0]

#card를 뽁고난 후의 행동
def do_card(draw) :
	global pos; global matrix_count

	if draw == 'GO' :
		pos = matrix.index('GO')
		matrix_count[pos] += 1
	elif draw == 'JAIL' :
		pos = matrix.index('JAIL')
		matrix_count[pos] += 1
	elif draw == 'C1' :
		pos = matrix.index('C1')
		matrix_count[pos] += 1
	elif draw == 'E3' :
		pos = matrix.index('E3')
		matrix_count[pos] += 1
	elif draw == 'H2' :
		pos = matrix.index('H2')
		matrix_count[pos] += 1
	elif draw == 'R1' :
		pos = matrix.index('R1')
		matrix_count[pos] += 1
	elif draw == 'R' :
		pos = next_R(pos)
		matrix_count[pos] += 1
	elif draw == '-3' :		#3칸 뒤로는 3칸 뒤에 CC가 있을수도 있어서 pos만 바꾸고
		pos = pos - 3		#메인 반복문에서 다시 한번 CC에 가는지 체크합니다.
	elif draw == 'U' :
		pos = next_U(pos)
		matrix_count[pos] += 1
	elif draw == 'Bomb' :
		matrix_count[pos] += 1
	
init_card(); where_U(); where_R()
while i < 1000000 :
	dice  = throw_dice()
	dice2 = throw_dice()

	if dice == dice2 :
		double_count += 1
	else :
		double_count = 0
	
	#더블이 3번 나오면 JAIL행
	if double_count == 3 :
		double_count = 0
		pos = matrix.index('JAIL')
		matrix_count[pos] += 1
		continue

	pos = (pos + dice + dice2) % matrix_size
	
	result = check_where(matrix[pos])
	
	if result == 'G2J' :
		pos = matrix.index('JAIL')
		matrix_count[pos] += 1
	elif result == 'CH' :
		draw = draw_card_CH()
		do_card(draw)

		if draw == '-3' :
			result = check_where(matrix[pos])
			if result == 'CC' :
				draw = draw_card_CC()
				do_card(draw)
			else :
				matrix_count[pos] += 1
	elif result == 'CC' :
		draw = draw_card_CC()
		do_card(draw)
	else :
		matrix_count[pos] += 1
	i += 1

#제가 많이 부족해서 sorting함수를 따로 구현을 해서 matrix, matrix_count를 
#함께 sorting해야 할 것 같습니다...
#matrix 리스트내에서 한꺼번에 할 수 있는 방법이 있을거 같긴한데
#파이썬을 시작한 지 며칠 안 돼서 잘 모르겠네요...

#matrix_count 기준으로 matrix_count, matrix 동시에 sorting하기
#bubble sort
length = len(matrix_count) - 1
temp = list(matrix)
for i in range(length) :
	for j in range(length - i) :
		if matrix_count[j] < matrix_count[j+1] :
			matrix_count[j], matrix_count[j+1] = matrix_count[j+1], matrix_count[j]
			matrix[j], matrix[j+1] = matrix[j+1], matrix[j]

print(str(temp.index(matrix[0])), str(temp.index(matrix[1])), str(temp.index(matrix[2])))