#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
struct segtree{

    int size;
    vector<long long> sums;
    void init(int n){
        size=1;
        while(size<n){
           size*=2; 
        }

        sums.assign(2*size,0LL);
        return;
    }
    void build(vector<int> &arr,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<arr.size())
                sums[x]=arr[lx];
            return;
        }
        int m=(lx+rx)/2;
        build(arr,2*x+1,lx,m);
        build(arr,2*x+2,m,rx);
        sums[x]=sums[2*x+1] + sums[2*x+2];
        return;

    }
    void build(vector<int> &arr){
        build(arr,0,0,size);
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            sums[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];
        return;
    }

    void set(int i,int val){
        set(i,val,0,0,size);
    }
    long long sum(int x,int s, int e,int lx,int rx){
        if(s>=rx || lx>=e)
            return 0;
        if(s>=lx && e<=rx)
            return sums[x];
        
        int m=(s+e)/2;
        return sum(2*x+1,s,m,lx,rx) + sum(2*x+2,m,e,lx,rx);
    }
    long long sum(int lx,int rx){
        return sum(0,0,size,lx,rx);
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    segtree st;
    st.init(n);
    st.build(arr);
    for(int i=0;i<m;i++){
        int op;
        cin>>op;
        if(op==1){
            int ind,v;
            cin>>ind>>v;
            st.set(ind,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<st.sum(l,r)<<endl;
        }
    }
    return 0;
}