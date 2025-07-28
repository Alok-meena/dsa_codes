Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 



brute force t.c:-O(n^2) and s.c:-O(height)

class Solution {
  public:
    int height(Node* root){
        //aor ager nodes ki terms me pucha ho to just 0 return kro yha pe because n nodes hai to n-1 edges hogi to ek km ke liye -1 bhej rhe the ham
        if(root==NULL) return -1; //height in terms of edges nikal rhe hai right to -1 return kiya 
        
        int left=height(root->left);
        int right=height(root->right);
        int ans=max(left,right)+1;
        return ans;
    }
    
    void solve(Node* root,bool &check){
        if(root==NULL) return ;
        
        int left=height(root->left);
        int right=height(root->right);
        int diff=abs(left-right);
        
        if(diff>1) check=false;
        
        solve(root->left,check);
        solve(root->right,check);
    }
    bool isBalanced(Node* root) {
        // Code here
        bool check=true;
        
        solve(root,check);
        
        return check;
    }
};

optimized  


class Solution {
  public:
    pair<int,bool> solve(Node* root){
        if(root==NULL) return {-1,true};
        
        pair<int,bool> left=solve(root->left);
        pair<int,bool> right=solve(root->right);
        
        int currheight=max(left.first,right.first)+1;
        int diff=abs(left.first-right.first);
        
        bool leftcheck=left.second;
        bool rightcheck=right.second;
        bool currcheck=diff>1?false:true;
        
        pair<int,bool> ans;
        ans.first=currheight;
        ans.second=leftcheck and rightcheck and currcheck; //we also have to combine all answers right so do it
        
        return ans;
        
    }
    bool isBalanced(Node* root) {
        // Code here
        return solve(root).second;
    }
};



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
     ans.second=max(left.second,right.second)+1; //ye hmara normal height ke liye hai remember it more clearly okk

     KYOKI HAME HEIGHT TO NORMALLY CALCULATE KRNI HI HAI TO YE TO KRNA OBVIOUS HAI 

        
        if(leftans && rightans && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;
}
bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.
    return balance(root).first;  //O(N)
}

same code but 
class Solution {
  public:
    pair<bool,int> Balance(Node *root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        
        pair<bool,int> l=Balance(root->left);
        pair<bool,int> r=Balance(root->right);
        
        bool leftpart=l.first;
        bool rightpart=r.first;
        int diff=abs(l.second-r.second); //bhai ye to karna hi hai right
        
        pair<bool,int>ans;
        ans.first=leftpart and rightpart and diff<2;
        ans.second=max(l.second,r.second)+1; 
        
        return ans;
    }
    
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node* root) {
        // Code here
        return Balance(root).first;
    }
};
