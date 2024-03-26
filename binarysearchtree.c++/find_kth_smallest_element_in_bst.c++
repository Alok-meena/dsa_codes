int solve(BinaryTreeNode<int>*root,int &i,int k){
    if(root==NULL){
        return -1;
    }
    int left=solve(root->left,i,k);
    if(left!=-1){// ager left -1 nhi h to hi return kro nhi to rhne do and i ka track rkha so bi reference pass kiya ise to reach to k
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right,i,k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}

t.c:-O(N)
s.c:-O(H)
