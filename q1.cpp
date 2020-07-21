#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int k,x;
        int ans=0;
        cin>>k>>x;
        int d=0;
        int c[26];
        for(int i=0;i<26;i++)
            c[i]=0;
        for(int i=0;i<s.length();i++){
            if(c[s[i]-'a']==x){
                if(k>0){
                    k--;
                }
                else{
                    break;
                }
            }
            else{
                c[s[i]-'a']++;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}