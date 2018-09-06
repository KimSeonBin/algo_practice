import sys
for i in range(0, int(sys.stdin.readline())):
    s = sys.stdin.readline().split()
    sc = [True for j in range(0, len(s))]
    for line in sys.stdin:
        line = line.split()

        if len(line) > 3:
            break
        for j in range(0, len(s)):
            if s[j] == line[2]:
                sc[j] = False
    for j in range(0, len(s)):
        if sc[j] == True:
            sys.stdout.write(s[j]+' ')
    print("")
