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
           return root;
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
Auxiliary Space:O(Height of Tree).


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

