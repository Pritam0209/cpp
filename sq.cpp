#include<bits/stdc++.h>
using namespace std;
bool judgeSquareSum(int n) 
{ 
    for (int i = 2; i * i <= n; i++) 
    { 
        int cnt = 0; 
        if (n % i == 0) 
        { 
            if(i%4==3){
                while (n % i == 0) 
                { 
                    cnt++; 
                    n /= i; 
                }
                if (cnt % 2 != 0) 
                    return false; 
            }   
        } 
    }
    return n % 4 != 3;
}
int sol(int l,int r){
    int ans=0;
    for(int i=l;i<=r;i++){
        if(judgeSquareSum(i))
            ans++;
    }
    return ans;
}
int main(){
    int l,r;
    cin>>l>>r;
    cout<<sol(l,r);
    return 0;
}