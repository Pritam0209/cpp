#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }
    int mid;
    if(n%2==0)
        mid=n/2;
    else
        mid=(n+1)/2;

    vector<int> arrGood;
    for(int i=1;i<=mid;i++){
        int beg=i;
        int end=(n)-i+1;
        // cout<<beg<<" "<<end<<endl;
        int x;
        if(beg!=end)
            x=arr[beg] ^ arr[end];
        else
            x=arr[beg];
        arrGood.push_back(x);
        // cout<<arrGood[i-1]<<endl;
    }
    int s = arrGood.size();
    int dp[s + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = arrGood[0];
    for (int i = 1; i < s; i++)
    {

        dp[i] = arrGood[i];
        // cout<<dp[i]<<endl;
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[i] < (dp[j] ^ arrGood[i]))
            {
                dp[i] = dp[j] ^ arrGood[i];
                // cout<<dp[i]<<" ";
            }
        }
    }
    int ans=dp[0];
    for(int i=1;i<s;i++){
         ans=max(ans,dp[i]);
    }

    cout << ans;


    return 0;
}