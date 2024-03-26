recursive approach:-

t.c:-O(N) s.c:-O(H)
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    if(root==NULL){
        return NULL;
    }

    if(root->data>P->data && root->data>Q->data){//are khuch nhi h suno lca nikalna hai to niche dono me se koi ek case hoga either dono left me honge ya to right
        //subtree me honge aor nhi to
        return LCAinaBST(root->left,P,Q);
    }
    if(root->data<P->data && root->data<Q->data){
        return LCAinaBST(root->right,P,Q);
    }
    return root;//nhi to ek lefttree me hoga aor ek right me to dono ka common ancestor bst me root node hi hoga aor khuch nhi
}


approach 2:- iterative to then t.c:-O(N) and s.c:-O(1)


TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    if(root==NULL){
        return NULL;
    }
    while(root!=NULL){
            if(root->data>P->data && root->data>Q->data)
              root=root->left;
            else  if(root->data<P->data && root->data<Q->data)
                 root=root->right;
            else 
                return root;
    }

  
}
