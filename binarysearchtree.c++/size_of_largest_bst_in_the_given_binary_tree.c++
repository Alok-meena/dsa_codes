Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.


brute force t.c:-O(n^2) and s.c:-O(h)



bool isbst(TreeNode *root,int mini,int maxi){
    if(root==NULL) return true;

    if(root->data>=mini and root->data<=maxi){
        bool left=isbst(root->left,mini,root->data);
        bool right=isbst(root->right,root->data,maxi);

        return left and right;
    }

    return false;
}

int countNodes(TreeNode *root){
    if(root==NULL) return 0;

    return 1+countNodes(root->left)+countNodes(root->right);
}
int largestBST(TreeNode * root){
    // Write your code here.
    if(root==NULL) return 0;

    if(isbst(root,INT_MIN,INT_MAX)){
        return countNodes(root);
    }

    return max(largestBST(root->left),largestBST(root->right));
}



approach 1:--

checking for isbst for left and right subtree and for each node but it is of O(N2) t.c so not optimised

approach 2:---
//to ek class bna li variables ki jinki hme requirement hai
class info{
    public:
     int maxi;
     int mini;
    bool isbst;
     int size;
};

info solve(TreeNode *root,int &ans){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    info left=solve(root->left,ans);//left ke liye call mar diya then right and data type rakha info to use the class
    info right=solve(root->right,ans);

    info currentnode;

    currentnode.size=left.size+right.size+1;// 1 add kiya for the root node itself
    currentnode.maxi=max(root->data,right.maxi);// class kee variables ko update kr diya
    currentnode.mini=min(root->data,left.mini);

    if(left.isbst && right.isbst && (root->data > left.maxi && root->data < right.mini)){// check for isbst 
        currentnode.isbst=true;
    }
    else{
        currentnode.isbst=false;
    }

    if(currentnode.isbst){// ager bst hai to ans ko update kr do max value of ans and currentnode ki size
        ans=max(ans,currentnode.size);
    }
   

    return currentnode;// then return kr do currentnode ko
}
int largestBST(TreeNode * root){
    // Write your code here.
    int maxsize=0;
    info temp=solve(root,maxsize);
    return maxsize;
}

t.c:- O(N) because each node is traversed only once
s.c:- O(1)
