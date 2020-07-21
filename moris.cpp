#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};
TreeNode* buildTree(vector<int> arr,int x,int n){
    if(x>=n)
        return NULL;
    if(arr[x]==-1)
        return NULL;
    TreeNode* root= new TreeNode(arr[x]);
    root->left=buildTree(arr,(x*2)+1,n);
    root->right=buildTree(arr,(x*2)+2,n);
    return root;
}
void morisTrav(TreeNode* root){
    TreeNode* tourist;
    tourist=root;
    int first,middle,last,pr;
    pr=-1;
    first=-1;
    middle=-1;
    last=-1;
    while(tourist!=NULL){
        TreeNode* guide;
        guide= tourist->left;
        if(guide!=NULL){
           // cout<<"here1"<<endl;
            while((guide->right)!=NULL && (guide->right)!=tourist){
                guide=guide->right;
            }
            if(guide->right==NULL){
                //cout<<"inside "<<guide->val<<" "<<tourist->val<<endl;
                guide->right=tourist;
                tourist=tourist->left;

            }
            else{
               // cout<<"here"<<endl;
                guide->right=NULL;
                cout<<tourist->val<<" ";
                if(pr==-1){
                    pr=tourist->val;
                }
                else{
                    int l=tourist->val;
                    if(pr>l){
                        if(first==-1 && middle==-1){
                            first=pr;
                            middle=l;
                        }
                        else{
                            last=l;
                        }
                    }
                    pr=l;
                }
                tourist=tourist->right;
            }
        }
        else{
            TreeNode* temp=tourist->right;
            cout<<tourist->val<<" ";
            if(pr==-1){
                    pr=tourist->val;
                }
                else{
                    int l=tourist->val;
                    if(pr>l){
                        if(first==-1 && middle==-1){
                            first=pr;
                            middle=l;
                        }
                        else{
                            last=l;
                        }
                    }
                    pr=l;
                }
            tourist=temp;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    TreeNode* root= buildTree(arr,0,n);
    morisTrav(root);
    return 0;
}