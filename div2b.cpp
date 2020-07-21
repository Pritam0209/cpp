void solve(){
    int n, x;
    cin >> n >> x;
    int arr[n];
    vector<int> pre(n+1,0);

    int cntZero = 0;
    for(int i = 0; i < n ;i++){
        cin >> arr[i];
        cntZero += (arr[i] == 0?1:0);
        pre[i+1]=pre[i] + arr[i];
    }
    
    if(pre[n]%x != 0)
    {
        cout << n << "\n";
        return;
    }
    
        int flnd=0;int frnd=0,fld=0,frd=0;
            int flag=0;
            for(int i=0;i<n+1;i++)
            {
                if(pre[i]%x!=0)
                {
                    flnd=i;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout << "-1\n";
                return;
            }
            for(int i=n;i>=0;i--)
            {
                if(pre[i]%x==0)
                {
                    frd=i;
                    break;
                }
            }
            for(int i=0;i<n+1;i++)
            {
                if(pre[i]%x==0)
                {
                    fld=i;
                    break;
                }
            }
            for(int i=n;i>=0;i--)
            {
                if(pre[i]%x!=0)
                {
                    frnd=i;
                    break;
                }
            }        
    cout << max(frd-flnd,frnd-fld) << "\n";
}