
def maxScore(n,arr):
    arr.sort(reverse=True)
    c=int(n/3)
    maxscore=0
    ind=1
    for i in range(c):
        maxscore=maxscore+arr[ind]
        ind+=2
    return maxscore
        

def main():
    t=int(input())
    for i in range(t):
        n=int(input())
        arr=list(map(int,input().strip().split(' ')))
        print(maxScore(n,arr))

if __name__ == "__main__":
    main()
    



