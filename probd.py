t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    arr=[[0 for i in range(n)] for j in range(n)]
    #print(arr)
    r=0
    c=0
    for i in range(k):
        #print(r,c)
        arr[r][c]=1
        r+=1
        c+=1
        c%=n
        if r==n:
            r=0
            c+=1
            c=c%n

    print(0) if k%n==0 else print(2) 
    for j in arr:
        print( ''.join(str(i) for i in j))
