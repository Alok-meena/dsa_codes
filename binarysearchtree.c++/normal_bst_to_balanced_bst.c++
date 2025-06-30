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

//iski t.c hai har bar O(n/2) call ho rha hai and by default har ek element ko node bnana hai alright to t.c : -O(n) ho jayegi alright 
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



written by me

void inorder(TreeNode<int>* root,vector<int>&in){
    if(root==NULL) return;

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

TreeNode<int>* bst(vector<int>&in,int low,int high){
    if(low>high){
        return NULL;
    }
    int mid=(low+high)/2;

    TreeNode<int>* root=new TreeNode<int>(in[mid]);
    root->left=bst(in,low,mid-1);
    root->right=bst(in,mid+1,high);

    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int>in;
    inorder(root,in);

    TreeNode<int>* newroot=bst(in,0,in.size()-1);
    return newroot;
}


t.c:-O(n) and s.c:-O(n) 
