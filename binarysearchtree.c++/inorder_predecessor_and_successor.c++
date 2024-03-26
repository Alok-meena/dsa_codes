User
TreeNode * minvalue(TreeNode * root){
    TreeNode * temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

TreeNode * maxvalue(TreeNode * root){
    TreeNode *temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
TreeNode * search(TreeNode * root, int val) {
    if (root == NULL || root->data == val)
        return root;
    if (root->data < val)
        return search(root->right, val);
    return search(root->left, val);
}
TreeNode * inorderPredecessor(TreeNode * root, int val) {
    TreeNode * target = search(root, val);
    if (target == NULL)
        return NULL;
    if (target->left == NULL)
        return NULL; // No predecessor exists if the target has a left subtree
    return maxvalue(target->left);
}
TreeNode * inorderSuccessor(TreeNode * root, int val) {
    TreeNode * target = search(root, val);
    if (target == NULL)
        return NULL;
    if (target->right == NULL)
        return NULL;
    return minvalue(target->right); 
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key){
    TreeNode *successor = inorderSuccessor(root, key);
    TreeNode *predecessor = inorderPredecessor(root, key);

    int a = (successor != NULL) ? successor->data : -1; // Return -1 if no successor exists
    int b = (predecessor != NULL) ? predecessor->data : -1; // Return -1 if no predecessor exists

    return {b,a};
}
