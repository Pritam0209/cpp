#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t="abacaba";
    int f=0;
    int st=t.length();
    for(int i=0;i<=n-7;i++){
        int j;
        for( j=i;j<i+7;j++){
            if(s[j]!=t[j-i]){
                break;
            } 
        }
        if(j==i+7){
            f++;       
        }
    }
    
    if(f>1){
        cout<<"NO"<<endl;
        return;
    }
    int ind=-1;
    
    if(f==0){
        for(int i=0;i<=n-7;i++){
            int c=0;
            int flag=0;
            string temp=s;
            for(int j=i;j<i+7;j++){
                if( temp[j]=='?'){
                    temp[j]=t[j-i];
                }
            }
            for(int j=0;j<=n-7;j++){
                string tempc=temp.substr(j,7);
                if(tempc==t){
                    c++;
                }
                if(c>1)
                    break;
            }
            if(c==1){
                ind=i;
                break;
            }

        }
        if(ind==-1)
            cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(int i=0;i<n;){
                if(i==ind){
                    cout<<t;
                    i+=7;
                    continue;
                }
                else if(s[i]=='?')
                    cout<<"z";
                else
                    cout<<s[i];
                i++;
                
            }
            cout<<endl;
        }
    }
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            if(s[i]=='?')
                cout<<"z";
            else
                cout<<s[i];
            
        }
        cout<<endl;
    }
    return;
    
     
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