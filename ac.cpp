#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
void solve(){
    long long  int n;
    cin>>n;
    vector<long long int> arr(n);
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    //sort(arr.begin(),arr.end());
    int o=0;
    int one=0;
    long long mx=-1;
    long long int mn=1000000000000000001;
    for(int i=0;i<n;i++){
        if(arr[i]>mx)
            mx=arr[i];
        if(mn>arr[i])
            mn=arr[i];
        if(arr[i]&1)
            o++;
        if(arr[i]==1)
            one=1;
    }
    if(one && o>1){
        cout<<"NO"<<endl;
        return;
    }
    long long temp=mx;
    int size=0;
    while(temp){
        size++;
        temp=temp>>1;
    }
    vector<int> setbit(size+2,0);
    //cout<<size<<endl;
    for(long long int i=0;i<n;i++){
        int c=0;
        int flag=0;
        int saraset=0;
        int kitnaset=0;
        long long tempa=arr[i];
        while(arr[i]){
            if(arr[i]&1){
                if(!setbit[c]){
                    flag=1;
                    setbit[c]=1;
                }
                kitnaset++;
            }
            saraset++;
            c++;
            arr[i]=arr[i]>>1;
        }
        if(saraset==kitnaset && (tempa!=mn ||tempa!=mx)){
            cout<<"NO"<<endl;
            return;
        }
        
        if(!flag){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;


}
int main(){
    IOS
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}