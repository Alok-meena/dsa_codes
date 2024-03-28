approach 1:- normal approach
BinaryTreeNode<int>* inserttobst(BinaryTreeNode<int>* root,int data){
    if(root==NULL){
        root=new BinaryTreeNode<int>(data);
        return root;
    }
    if(data<root->data){
         root->left=inserttobst(root->left,data);
    }
    else{
        root->right=inserttobst(root->right,data);
    }
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    BinaryTreeNode<int>* root=NULL;
    for(int i=0;i<preorder.size();i++){
        root=inserttobst(root,preorder[i]);
    }
    return root;
}


approach 2:---
similarly as we have done in trees that creation of tree from inorder and preorder and inorder and postorder so we can create inorder from both by sorting the
elements okkk... so t.c:-O(NlogN) s.c:-O(N)



approach 3:--


using concept of is bst of rangebased answer 
//smja do jldi se
BinaryTreeNode<int>* solve(vector<int>&preorder,int &i,int mini,int maxi){
    if(i>=preorder.size()){// base condition is when u will move out of the array
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>maxi){// lie out of the range then return null also
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[i++]);// nhi to node create kr do aor left right ki call mar do
    root->left=solve(preorder,i,mini,root->data);
    root->right= solve(preorder,i,root->data,maxi);
    return root;

        

}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
    return solve(preorder,i,mini,maxi);
}

t.c:-O(N)



without using the min variable :---
    \

    BinaryTreeNode<int>* getBST(vector<int>& preorder,int maxi,int &index){
        if(index==preorder.size()|| preorder[index]>maxi ){
            return NULL;
        }
        
        BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[index++]);
        
        root->left=getBST(preorder,root->data,index);
        
        root->right=getBST(preorder,maxi,index);
        
        return root;
    }

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
      int index=0;
      return getBST(preorder,INT_MAX,index);
}


