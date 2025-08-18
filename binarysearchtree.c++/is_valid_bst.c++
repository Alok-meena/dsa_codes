bool isbst(BinaryTreeNode<int> *root,int min,int max){
    if(root==NULL){
        return true;
    }

    //equal to k sign hta do bs
    if(root->data>min && root->data<max){// mtlb ager -infinite aor +infinite ki range me hai to insert kr lo left ki call then right ki then return both
        bool left=isbst(root->left,min,root->data);
        bool right=isbst(root->right,root->data,max);
        return left && right;
    }
    return false;
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
   return  isbst(root,INT_MIN,INT_MAX);

}
simple hai copy me explanantion hai iska  vhi kai ke range define kr di bs ager left me jayenge to -infinite se root ke data tk and right me root ke data
se +infinite tk bs ow return false

t.c:- O(N)
s.c:-O(H) h is the height of the tree

to bs vhi check kiya ki elements us rang me hai ki nhi




2nd appraoch :----- 
use inorder traversal then store the values and check whether they are sorted or not because inorder traversal of bst gives a sorted array 

void inorder(BinaryTreeNode<int> *root, vector<int> &ans){

    if(root == NULL) return;

 

    inorder(root -> left, ans);

    ans.push_back(root -> data);

    inorder(root -> right, ans);

}

bool validateBST(BinaryTreeNode<int> *root) {

    // Write your code here

    if(root == NULL) return true;

 

    vector<int> ans;

    inorder(root, ans);

 

    for(int i = 0; i < ans.size() - 1; i++){

        if(ans[i] > ans[i + 1]) return false;

    }

    return true;

}

t.c:-O(n) and s.c:-O(n)
