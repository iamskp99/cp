a,b = map(int,input().split())
if a == b:
    print(0)
    exit()

e1 = bin(a)[2:]
e2 = bin(b)[2:]
diff = len(e2)-len(e1)
e1 = ("0"*diff)+e1
e1 = e1[::-1]
e2 = e2[::-1]
ans = ["0"]*len(e2)
for i in range(len(e2)):
    if b-a >= 2**i:
        ans[i] = "1"

    else:
        if int(e1[i])^int(e2[i]) == 1:
            ans[i] = "1"

print(int("".join(ans[::-1]),2))