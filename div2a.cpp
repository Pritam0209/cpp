#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n), ans;
    for(int  i = 0; i < n ;i++){
        cin >> arr[i];
    }
    unordered_set<int> hs;
    vector<int> a1;
      for(int i=0;i<n-1;i++)
            {
                if(i+1<n && arr[i+1]>arr[i])
                {
                    int a=i;
                    while(a<n-1 && arr[a+1]>arr[a])
                    {
                        a++;
                    }
                    if(hs.find(arr[i]) == hs.end())
                    {
                        hs.insert(arr[i]);
                        a1.push_back(arr[i]);
                    }
                    if(hs.find(arr[a]) == hs.end())
                    {
                        hs.insert(arr[a]);
                        a1.push_back(arr[a]);
                    }
                   
                    i=a;
                    //continue;
                }
                if(i+1<n && arr[i+1]<arr[i])
                {
                    int a= i;
                    while(a<n-1 && arr[a+1]<arr[a])
                    {
                        a++;
                    }
                    if(hs.find(arr[i]) == hs.end())
                    {
                        hs.insert(arr[i]);
                        a1.push_back(arr[i]);
                    }
                    if(hs.find(arr[a]) == hs.end())
                    {
                        hs.insert(arr[a]);
                        a1.push_back(arr[a]);
                    }
                    i=a-1;
                    //continue;
                }
            }
            cout << a1.size() << "\n";
            for(int i=0;i<a1.size();i++)
            {
                cout << a1[i] << " ";
            }
    cout << "\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}