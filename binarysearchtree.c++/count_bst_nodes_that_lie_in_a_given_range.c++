


class Solution {
  public:
    void solve(Node *root,int l,int h,int &ans){
        if(root==NULL) return;
        
        solve(root->left,l,h,ans);
        if(root->data>=l and root->data<=h){
            ans++;
        }
        solve(root->right,l,h,ans);
    }
    int getCount(Node *root, int l, int h) {
        // your code here
        int ans=0;
        
        solve(root,l,h,ans);
        
        return ans;
    }
};

t.c:-O(n) and s.c:-O(h) alright
