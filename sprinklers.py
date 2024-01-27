t =  int(input())
for x in range(t):
    n , nq = map(int,input().split())
    X = list(map(int,input().split()))
    R = list(map(int,input().split()))
    arr = [0]*(4*n+5)
    for i in range(n):
        left = X[i] - R[i] + 2*n
        right = X[i] + R[i] + 2*n + 1
        if X[i] > 0:
            left=max(left,2*n)
        else:
            right = min(right,2*n)
        arr[left] +=1
        arr[right]-=1
    print(arr)
    for i in range(4*n+5):
        arr[i]+=arr[i-1]
    for j in range(nq):
        inp = int(input())
        inp+=2*n
        print(arr[inp])