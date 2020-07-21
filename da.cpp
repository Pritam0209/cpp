#include<bits/stdc++.h>
using namespace std;
long long int solg(long long int div){
    // cout<<"hello";
    int c=0;
    while(true){
        if(div%8==0){
            div=div/8;
            c++;
            if(div==1)
                return c;
        }
        else if(div%4==0){
            div=div/4;
            c++;
            if(div==1)
                return c;
        }
        else if(div%2==0){
            div=div/2;
            c++;
            if(div==1)
                return c;
        }
        else{
            return -1;
        }
    }


}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int a,b;
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        //cout<<a<<" "<<b<<endl;
        if(a==b){
            cout<<"0"<<endl;
        }
        else if(a<b){
            if(b%a!=0)
                cout<<"-1"<<endl;
            else{
                long long int div;
                div=b/a;
                cout<<solg(div)<<endl;
                
            }
            
            
        }
    }
    return 0;
}