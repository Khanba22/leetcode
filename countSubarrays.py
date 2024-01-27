x = int(input())
for l in range(x):
    n,m,k = map(int,input().split())
    arr = list(map(int,input().split()))
    b = m*arr
    count = 0
    for i in range(m*n):
        ptr1 = i
        res = 0
        while ptr1 < m*n:
            res+=b[ptr1]
            ptr1+=1
            if res <= k:
                count+=1
            else:
                break
    print(count)