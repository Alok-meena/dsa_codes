to ye avl tree ka code hai because ye balanced bst hai 



void inorder(TreeNode<int>* root,vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
// bs mid find krke usko root bna diay aor same binarysearch ki tarah create kiya balanced bs create kr diya
TreeNode<int>* inordertobst(int s,int e,vector<int>&in){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode<int>* root=new TreeNode<int>(in[mid]);
    root->left=inordertobst(s,mid-1,in);
    root->right=inordertobst(mid+1,e,in);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int>in;
    inorder(root,in);

    return inordertobst(0,in.size()-1,in);
}


Time Complexity
O(N), where N is the number of nodes in the Binary Search Tree.

 

As we are traversing each node twice, the time complexity is O(N).

Space Complexity
O(N), where N is the number of nodes in the Binary Search Tree.

 

Even in the worst case, the recursion stack will grow no more than log(N)
and since we are storing all the node values in the array, the space complexity is O(N).
