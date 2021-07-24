import sys
input = sys.stdin.readline
n,k = map(int,input().split())
limit = bin(n)[2:].count("1")
if (k < limit) or k > n:
    print("NO")
    exit()

cnt = limit
bits = [0]*64
s = bin(n)[2:][::-1]
for j in range(len(s)):
    if s[j] == "1":
        bits[j] = 1

flag = 0
i = 63
while cnt < k and i > 0:
    while bits[i]:
        bits[i-1] += 2
        bits[i] -= 1
        cnt += 1
        if cnt == k:
            flag = 1
            break

    if flag:
        break

    i -= 1

print("YES")
ans = []
for i in range(len(bits)):
    for j in range(bits[i]):
        ans.append(2**i)

print(*ans)