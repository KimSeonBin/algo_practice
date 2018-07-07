import re

sen = input()
happy = 0; sad = 0
happy_reg = ':-\)'; sad_reg = ':-\('

p = re.compile(happy_reg)
result = p.findall(sen)
happy = len(result)

p = re.compile(sad_reg)
result = p.findall(sen)
sad = len(result)

if happy > sad:
    print('happy')
elif happy < sad:
    print('sad')
elif happy == 0 and sad == 0:
    print('none')
elif happy == sad:
    print('unsure')
