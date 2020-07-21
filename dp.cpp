#include<bits/stdc++.h>
using namespace std;
long long int sol(int a[],int n,int c,int k,int s,int i){
    if(s<k || i>=n)
        return 0;
    if(c>=k){
        return 1+sol(a,n,c+a[i],k,s-a[i],i+1)+sol(a,n,c,k,s,i+1);
    }        
    return sol(a,n,c+a[i],k,s-a[i],i+1)+sol(a,n,c,k,s,i+1);
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    long long int s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s=s+a[i];
    }
    long long int ans= sol(a,n,0,k,s,0);
    cout<<ans<<endl;
    return 0;
}