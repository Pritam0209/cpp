#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
struct segtree{

    int size;
    vector<int> value;
    void init(int n){
        size=1;
        while(size<n){
           size*=2; 
        }

        value.assign(2*size,0LL);
        return;
    }
    void build(vector<int> &arr,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<arr.size())
                value[x]=arr[lx];
            return;
        }
        int m=(lx+rx)/2;
        build(arr,2*x+1,lx,m);
        build(arr,2*x+2,m,rx);
        value[x]=min(value[2*x+1] , value[2*x+2]);
        return;

    }
    void build(vector<int> &arr){
        build(arr,0,0,size);
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            value[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        value[x]=min(value[2*x+1],value[2*x+2]);
        return;
    }

    void set(int i,int val){
        set(i,val,0,0,size);
    }
    long long calc(int x,int s, int e,int lx,int rx){
        if(s>=rx || lx>=e)
            return INT_MAX;
        if(s>=lx && e<=rx)
            return value[x];
        
        int m=(s+e)/2;
        return min(calc(2*x+1,s,m,lx,rx) , calc(2*x+2,m,e,lx,rx));
    }
    long long calc(int lx,int rx){
        return calc(0,0,size,lx,rx);
    }
};
int main(){
    IOS
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
            cout<<st.calc(l,r)<<endl;
        }
    }
    return 0;
}