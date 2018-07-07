sen = input()
sen_len = len(sen);
most_count = 0

for iter in range(0, sen_len):
    sen_temp = sen[iter:sen_len]
    temp = 0
    prefix = [0 for i in range(0, sen_len-iter)]
    for i in range(1, sen_len-iter):
        while temp > 0 and sen_temp[i] != sen_temp[temp]:
            temp = prefix[temp-1]
        if sen_temp[temp] == sen_temp[i]:
            temp += 1
            prefix[i] = temp
            if most_count < temp:
                most_count = temp
print(most_count)
