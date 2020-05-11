#include <bits/stdc++.h>
using namespace std;
typedef struct abc{
	long long int t,l,r;
}b;
void updateBIT(long long int BITree[],long long  int n,long long  int index,long long  int val)
{
    index = index + 1;

    while (index <= n)
    {
        BITree[index] += val;

        index += index & (-index);
    }
}

long long int *constructBITree(long long int arr[],long long  int n)
{
    long long int *BITree = new long long int[n+1];
    for (long long int i=1; i<=n; i++)
        BITree[i] = 0;
    for (long long int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
 
    return BITree;
}

long long int getSum(long long int BITree[],long long int index)
{
    long long int sum = 0;
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void update(long long int BITree[],long long int l,long long int r,long long int n,long long int val)
{
    updateBIT(BITree, n, l, val);
    updateBIT(BITree, n, r+1, -val);
}
int main()
{
	long long int t,i;
	cin>>t;
	while(t--){
		long long int n,m;
		cin>>n>>m;
		b queries[m];
		long long int count[m];
		for(i=0;i<m;i++)
			count[i]=0;
		long long int arr[n];
		for(i=0;i<n;i++)
			arr[i]=0;
		long long int *counter = constructBITree(count, m);
		for(i=0;i<m;i++){
			cin>>queries[i].t>>queries[i].l>>queries[i].r;
			queries[i].l--;
			queries[i].r--;			
		}
		for(i=m-1;i>=0;i--)
		{
			if(queries[i].t==2){
				update(counter,queries[i].l,queries[i].r,m,(getSum(counter,i)+1)%1000000007);
			}
		}
		/*for(i=0;i<m;i++){
			cout<<getSum(counter,i)+1<<" ";
		} */
		long long int *array = constructBITree(arr, n);
		for(i=0;i<m;i++)
		{
			if(queries[i].t==1){
				update(array,queries[i].l,queries[i].r,n,(getSum(counter,i)+1)%1000000007);
			}
		}
		for(i=0;i<n;i++)
		{
			cout<<(getSum(array,i)%1000000007)<<" ";
		}
		cout<<endl;	
		
	}
	return 0;
}