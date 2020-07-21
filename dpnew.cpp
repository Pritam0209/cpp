#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr[i] = val;
    }
    unordered_map<int, int> mp;

    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        // int d=arr[i];
        if (mp.find(i) != mp.end() && mp.find(n - i + 1) != mp.end())
        {
            //cout<<i<<" "<<(n-i+1)<<"\n";
            vec.push_back(arr[i] ^ (n - i + 1));
            // arr[n-i]=-1;
            mp.erase(i);
            mp.erase(n - i + 1);
        }
    }
    int res = 1;

    n = vec.size();
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = vec[0];
    //cout<<dp[0]<<" ";
    for (int i = 1; i < n; i++)
    {

        dp[i] = vec[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[i] < (dp[j] ^ [i]))
            {
                dp[i] = dp[j] ^ vec[i];
                // cout<<dp[i]<<" ";
            }
        }
    }

    cout << dp[n - 1];

    //cout<<res<<" ";
}