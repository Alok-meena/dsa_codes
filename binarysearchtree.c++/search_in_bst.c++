recursive approach:-

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(x<root->data){
        searchInBST(root->left,x);
    }
    else{
        searchInBST(root->right,x);
    }
}

iterative approach:-


bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *temp=root;
    while(temp!=NULL){
        
        if(temp->data==x){
            return true;
        }
        if(x<temp->data){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}
