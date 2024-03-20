pair<bool,int> balance(TreeNode<int>* root){
     if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
     }
        
     pair<bool,int>left=balance(root->left);
     pair<bool,int>right=balance(root->right);

     bool leftans=left.first;
     bool rightans=right.first;

     bool diff=abs(left.second-right.second)<=1;
     pair<bool,int>ans;
     ans.second=max(left.second,right.second)+1;

        
        if(leftans && rightans && diff){
            ans.first=true;
        }
        else{
            ans.second=false;
        }
        return ans;
}
bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.
    return balance(root).first;
}
