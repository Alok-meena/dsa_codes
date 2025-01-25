Given a Binary Tree with all unique values and two nodes value, n1 and n2. 
The task is to find the lowest common ancestor of the given two nodes.
We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Example 1:

Input:
n1 = 2 , n2 = 3  
       1 
      / \ 
     2   3
Output: 1
Explanation:
LCA of 2 and 3 is 1.



just store path of both and start compare from root till then both parent is not equal then return just before node
class Solution {
  public:
    // Function to return the lowest common ancestor in a Binary Tree.
    bool solve(Node *root,vector<Node*>&ans,int val){
        if(root==NULL){
            return false;
        }
        
        ans.push_back(root);
        if(root->data==val) return true;
        
        if((solve(root->left,ans,val)) or (solve(root->right,ans,val))){
            return true;
        }
        
        ans.pop_back();
        
        return false;
    }
    Node* lca(Node* root, int n1, int n2) {
        // Your code here
        vector<Node*>a;
        vector<Node*>b;
        
        if(solve(root,a,n1) and solve(root,b,n2)){
            int i=0;
            while(i<a.size()){
                if(a[i]!=b[i]){
                    break;
                }
                i++;
            }
            
            return a[i-1];
        }
        
        return NULL;
    }
};

t.c:-O(n+m)=O(n) and s.c:-O(h+h)=O(h)

another approach searching both at the same time

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL){
           return root;
       }
       
       if(root->data==n1 || root->data==n2){
           return root;// because vo khud hi ancestor hoga ager data equal ho gya root ke
       }
       
       Node *leftans=lca(root->left,n1,n2);
       Node *rightans=lca(root->right,n1,n2);

      // handling Null cases
       if(leftans!=NULL && rightans!=NULL){
           return root;
       }
       else if(leftans!=NULL && rightans==NULL){
           return leftans;
       }
       else if(leftans==NULL && rightans!=NULL){
           return rightans;
       }
    }
};




Time Complexity:O(N).
Auxiliary Space:O(Height of Tree). //and O(N) in case of skewed tree


//And instead of node if we have to return a int value then the code is like :- 

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    if(root==NULL){
           return -1;
       }
       
       if(root->data==x || root->data==y){
           return root->data;
       }
       
       int leftans=lowestCommonAncestor(root->left,x,y);
       int rightans=lowestCommonAncestor(root->right,x,y);
       
       if(leftans!=-1 && rightans!=-1){
           return root->data;
       }
       else if(leftans!=-1 && rightans==-1){
           return leftans;
       }
       else if(leftans==-1 && rightans!=-1){
           return rightans;
       }
}

we can also write like 

class Solution {
  public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2) {
        // Your code here
        if(root==NULL){
            return NULL;
        }
        
        if(root->data==n1 or root->data==n2){
            return root;
        }
        
        Node *left=lca(root->left,n1,n2);
        Node *right=lca(root->right,n1,n2);
        
        if(left and right){
            return root;
        }
        else if(!left and right){
            return right;
        }
        else if(left and !right){
            return left;
        }
        else return NULL;
    }
};

