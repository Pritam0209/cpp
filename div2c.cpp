#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <numeric>
#include <utility>
#include <set>
#include <queue>
#include <cstring>
#include <bitset>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef struct segment segment;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
 
int cnt1[200001];
int cnt2[200001];
int main()
{
  int n; cin >> n;
  int a[n], b[n];
  
  for(int i=0;i<n;i++){
    cin >> a[i];
    cnt1[a[i]] = i;
  }
  for(int i=0;i<n;i++){
    cin >> b[i];
    cnt2[b[i]] = i;
  }
  
  int ans = 0;
  int ara[200001];
  map<int,int> mp;
  for(int i=1;i<=n;i++){
    if(cnt2[i]-cnt1[i]>=0)mp[abs(cnt1[i]-cnt2[i])]++;
    else mp[n+cnt2[i]-cnt1[i]]++;
  }
  int mx = 0;
  for(auto i:mp){
    mx = max(mx,i.second);
  }
  cout<<mx;
}