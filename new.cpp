#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   vector<int> ans;
   
   while(t--){
      int n;
      cin>>n;
      char x;
      string v="!#$%&*@^~";
      unordered_map<char,int> m;
      for(int i=0;i<n;i++){
         cin>>x;
         m[x]=1;
      }
      unordered_map<char,int> nl;
      string s="";
      for(int i=0;i<n;i++){
         cin>>x;
         nl[x]=1;
      }
      int l=v.size();
      for(int i=0;i<l;i++){
         if(m[v[i]]==1 && nl[v[i]]==1){
            s=s+v[i]+" ";
         }
      }
      cout<<s<<endl;
   }
}