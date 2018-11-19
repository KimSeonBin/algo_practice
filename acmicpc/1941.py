def checkConnect(points):
    count = 1
    check = [False] * len(points)
    dfs = [0]
    check[0] = True
    while len(dfs) > 0 and count < len(points):
        index = dfs.pop()
        for i in range(len(points)):
            if check[i]:
                continue

            a = points[index]
            b = points[i]

            if abs(a // 5 - b // 5) == 1 and a % 5 == b % 5:
                if not check[i]:
                    check[i] = True
                    count += 1
                    dfs.append(i)
            elif abs(a - b) == 1 and a // 5 == b // 5:
                check[i] = True
                count += 1
                dfs.append(i)

    if count == len(points):
        return True
    return False

def checkAnswer(princess, points):
    points = [[item // 5, item % 5] for item in points]
    temp = 0

    for point in points:
        if princess[point[0]][point[1]] == 'S':
            temp += 1
    if temp >= 4:
        return 1
    return 0

def sol(princess):
    result = 0
    for a in range(0, 25):
        for b in range(a+1, 25):
            for c in range(b+1, 25):
                for d in range(c+1, 25):
                    for e in range(d+1, 25):
                        for f in range(e+1, 25):
                            for g in range(f+1, 25):
                                points = [a, b, c, d, e, f, g]
                                if not checkConnect(points):
                                    continue
                                result += checkAnswer(princess, points)
    return result

if __name__ == '__main__':
    princess = [input() for _ in range(5)]
    print(sol(princess))
