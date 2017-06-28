import re
def split_blank(sentence) :
	result = re.sub('[ \t]', '', sentence)
	return result

#단순하게 생각해서 각 줄마다 앞의 공백을 지우고 '/'나 '*'로 시작하면 주석이고 아니면 라인이다라고 생각했습니다.
#그 줄 통채로 주석이 될려면 맨 앞에서 주석기호를 달아야하기 때문에 이런 방식이 먹히지 않을까 생각했습니다
f = open('./test.java', 'r')
count = 0
while True :
	line = f.readline()
	if not line : break
	line = split_blank(line)
	if line[0] == '/' or line[0] == '*' or line[0] == '\n':
		continue
	else :
		count += 1
f.close()
print('source code line count {0}'.format(count))