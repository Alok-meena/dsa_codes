recursive approach:-

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root==NULL){
        return false;
    }

    // it is absolutely correct ager ham pahle hi left jate to wrong ho jata pahle chcek kro then according to val left y right jao alright
    
    if(root->data==x){
        return true;
    }
    if(x<root->data){
        return searchInBST(root->left,x);
    }
    else{
        return searchInBST(root->right,x);
    }

    return false;
}

t.c:-O(logn) and s.c:-O(logn) which is height and u know in case of skeew tree okk but

iterative approach:-


t.c:-O(logn) and s.c:-O(1)

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
