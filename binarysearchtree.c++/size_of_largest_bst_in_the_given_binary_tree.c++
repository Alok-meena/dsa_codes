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

are bhai suno ye khuch nya nhi hai ye vhi hai jo hamne binary tree tree ka kiya tha balance hai ya nhi binary tree to vha hamne pair return kiya tha aor yha
info type ki class return kr rhe hai as here we require 4 variables okk

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

    currentnode.size=left.size+right.size+1;// 1 add kiya for the root node itself //okk curr size me ham currsize hi bhejenge maxsize nhi , varna galat ans add hoga
    currentnode.maxi=max(root->data,right.maxi);// class kee variables ko update kr diya
    currentnode.mini=min(root->data,left.mini);//min ya to curr value ya fir left ki value hogi alright 

    if(left.isbst && right.isbst && (root->data > left.maxi && root->data < right.mini)){// check for isbst  aor value left ki maxi and right ki mini ke beech me hona chiahei
            
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


2nd time


class info{
    public:
    bool isbst;
    int size;
    int mini;
    int maxi;
};

info solve(TreeNode *root,int &maxsize){
    if(root==NULL){
        return {true,0,INT_MAX,INT_MIN};
    }

    info left=solve(root->left,maxsize);
    info right=solve(root->right,maxsize);

    if(left.isbst and right.isbst and root->data>left.maxi and root->data<right.mini){
        int currsize=left.size+right.size+1;
        maxsize=max(maxsize,currsize);
        return {true,currsize,min(root->data,left.mini),max(root->data,right.maxi)}; // okk curr size me ham currsize hi bhejenge maxsize nhi , varna galat ans add hoga
    }

    return {false,0,0,0};
}


int largestBST(TreeNode * root){
    // Write your code here.
    int maxsize=0;
    info ans=solve(root,maxsize);
    return maxsize;
}
