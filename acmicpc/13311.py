# temp = [i+1 for i in range(0, 1000)]
# tempc = [True for i in range(0, 1000)]
# prime = []
# luck = []
#
# for i in temp:
#     if tempc[i-1] is False:
#         continue
#     if i == 1:
#         continue
#     prime.append(i)
#     index = i
#     while (i-1) + index < 1000:
#         tempc[(i-1) + index] = False
#         index += i
#
# answer = 1
# for i in prime:
#     temp = i
#     while temp * i < 1000:
#         temp *= i
#
#     answer *= temp
#
# print(answer-1)
print(-1)
