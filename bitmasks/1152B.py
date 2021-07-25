x = int(input())
ans = []
z = 0
while True:
    w = bin(x)[2:][::-1]
    cnt = w.count("1")
    if cnt == 0 or cnt == len(w):
        break

    ind = 0
    for i in range(len(w)):
        if w[i] == "1":
            ind = i

    z += 1
    ans.append(ind+1)
    x = ((2**(ind+1))-1)^x
    w = bin(x)[2:][::-1]
    cnt = w.count("1")
    if cnt == 0 or cnt == len(w):
        break

    x += 1
    z += 1

print(z)
print(*ans)