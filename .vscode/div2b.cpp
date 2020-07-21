#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> t(n);
    vector< pair<int, int > > t1;
    vector< pair< int, int > > t2;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    for(int i=0;i<n;++i){
        cin>>t[i];
    }
    for(int i=0;i<n;i++){
        if(t[i]==1)
            t2.push_back( make_pair(arr[i],i) );
        else
            t1.push_back( make_pair(arr[i],i) ); 
    }
    int t1_size=t1.size();
    int t2_size=t2.size();
    if(t1_size==0 || t2_size==0){
        for(int i=1;i<n;++i){
            if(arr[i]<arr[i-1]){
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
        return;
    }
    sort(t1.begin(),t1.end());
    sort(t2.begin(),t2.end());
    int s1=0;
    int s2=0;
    while(s1<t1_size && s2<t2_size){
        if(t1[s1].first <= t2[s2].first){
            s1++;
        }
        else{
            s2++;
        }
    }
    if(s1!=t1_size){
        while(s1<(t1_size-1)){
            if( (t1[s1].first > t1[s1+1].first ) && ( t1[s1].second > t1[s1+1].second )){
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
        return;
    }
    if(s2!=t2_size){
        while(s2<(t2_size-1)){
            if( (t2[s2].first > t2[s2+1].first ) && ( t2[s2].second > t2[s2+1].second )){
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}