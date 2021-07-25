# def chk(e):
#     flag = 1

a,b = map(int,input().split())
low = len(bin(2**(len(bin(a)[2:]))-1)[2:])
high = len(bin(2**(len(bin(b)[2:]))-1)[2:])
ans = 0
for i in range(low,high+2):
    c = list(bin(2**i-1)[2:])
    for k in range(1,len(c)):
        c[k] = "0"
        e = "".join(c)
        num = int(e,2)
        if num >= a and num <= b:
            ans += 1

        c[k] = "1"

print(ans)