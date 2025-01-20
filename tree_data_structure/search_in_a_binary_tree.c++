bool preordertraversal(node* &curr,int ele){
    if(curr==NULL){
        return false;
    }
    if(curr->data==ele) return true;

    
    if(preordertraversal(curr->left,ele)) return true;
    if(preordertraversal(curr->right,ele)) return true;

    return false;

}
