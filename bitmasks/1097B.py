import sys
input = sys.stdin.readline
n = int(input())
l = []
for i in range(n):
    x = int(input())
    l.append(x)

limit = 2**n
g = bin(limit-1)[2:]
flag = 0
for i in range(limit):
    num = ("0"*(len(g)-len(bin(i)[2:])))+bin(i)[2:]
    init = 0
    for j in range(len(num)):
        x = l[j]
        if num[j] == "0":
            init = (init-x)%360

        if num[j] == "1":
            init = (init+x)%360

    if init == 0:
        flag = 1
        break

if flag:
    print("YES")

else:
    print("NO")