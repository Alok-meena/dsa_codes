Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0








class Solution {
    private:
    int countNode(struct Node * tree){ //O(N)
        if(tree==NULL){
            return 0;
        }
        
        int ans=countNode(tree->left)+countNode(tree->right)+1;
        return ans;
    }
    
    bool cbt(struct Node * tree,int index,int count){  //O(N)
        if(tree==NULL){
            return true;
        }
        if(index>=count){  //0- based indexing hai so equal to use karna hoga
            return false;
        }
        else{
            bool left=cbt(tree->left,2*index+1,count);
            bool right=cbt(tree->right,2*index+2,count);
            return (left && right);
        }
    }
    
    bool ismaxheap(struct Node * tree){  //O(N)
        if(tree->left==NULL && tree->right==NULL){
            return true;
        }
        if(tree->right==NULL){
            return (tree->data>tree->left->data);
        }
        else{
            bool left=ismaxheap(tree->left);
            bool right=ismaxheap(tree->right);
            
            return (left && right && (tree->data>tree->left->data && tree->data>tree->right->data));
        }
    }
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int index=0;
        int count=countNode(tree);
        if(cbt(tree,index,count) && ismaxheap(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};

Expected Time Complexity: O(N) // because har case me complete tree ko traverse kiya hai
Expected Space Complexity: O(N)



if elements can be equal then 

int countNode(BinaryTreeNode<int>* root){
        if(root==NULL){ 
            return 0;
        }
        
        int ans=countNode(root->left)+countNode(root->right)+1;
        return ans;
    }
    
    bool cbt(BinaryTreeNode<int>* root,int index,int count){
        if(root==NULL){
            return true;
        }
        if(index>count){  //0- based indexing hai so equal to use karna hoga
            return false;
        }
        else{
            bool left=cbt(root->left,2*index+1,count);
            bool right=cbt(root->right,2*index+2,count);
            return (left && right);
        }
    }
    
    bool ismaxheap(BinaryTreeNode<int>* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->right==NULL){
            return (root->data>=root->left->data);
        }
        else{
            bool left=ismaxheap(root->left);
            bool right=ismaxheap(root->right);
            
            return (left && right && (root->data>=root->left->data && root->data>=root->right->data));
        }
    }
bool isBinaryHeapTree(BinaryTreeNode<int>* root) 
{
    // Write your code here.
    int index=0;
        int count=countNode(root);
        if(cbt(root,index,count) && ismaxheap(root)){
            return true;
        }
        else{
            return false;
        }
}
