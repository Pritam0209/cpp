
def calcScore(n,height,power):
    if n==1 :
        return power[0]
    i=0
    start=0
    ans=0
    while i<(n-1):
        start=i
        if height[i]!=height[i+1] :
            ans+=power[i]
            i+=1
            continue
        while i<n-1 and height[i]==height[i+1] :
            i+=1
        i+=1
        dp=[None]*10
        if (i-start)==2 :
            ans+=max(power[start],power[start+1])
            continue
        dp[0]=power[start]
        dp[1]=max(power[start],power[start+1])
        start+=2
        k=2
        while start<i :
            dp[k]=max(dp[k-1],power[start]+dp[k-2])
            ans+=dp[k]
            start+=1
            k+=1
        i+=1
    
    if height[n-1]!=height[n-2]:
        ans+=power[n-1]

    return ans


def main():
    t=int(input())
    for i in range(t):
        n=int(input())
        height=list(map(int,input().strip().split(' ')))
        power=list(map(int,input().strip().split(' ')))
        print(calcScore(n,height,power))


if __name__ == "__main__":
    main()