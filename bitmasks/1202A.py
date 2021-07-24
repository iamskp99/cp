for _ in range(int(input())):
    x = input()
    y = input()
    y = ("0"*(len(x)-len(y)))+y
    x = x[::-1]
    y = y[::-1]
    pos2 = y.find("1")
    pos1 = 0
    for i in range(pos2,len(x)):
        if x[i] == "1":
            pos1 = i
            break

    print(pos1-pos2)