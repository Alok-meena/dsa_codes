Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

approach 1:- 

     but then the same problem that the time compleixty will be of O(N2) , because it also includes isbalanced and height recursive calls
     class Solution{
    private:
    int height(Node *root){
        if(root==NULL){
            return 0;
        }
        
        int left=height(root->left);
        int right=height(root->right);
        
        int ans=max(left,right)+1;
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root==NULL){
            return true;
        }
        
        int left=isBalanced(root->left);
        int right=isBalanced(root->right);
        
        int diff=abs(height(root->left)-height(root->right))<=1;
        
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};

approach 2:-
     
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
