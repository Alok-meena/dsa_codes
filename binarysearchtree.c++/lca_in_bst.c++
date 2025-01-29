brute force

bool solve(TreeNode *root,TreeNode *a,vector<TreeNode*>&v){
    if(root==NULL){
        return false;
    }

    v.push_back(root);

    if(root->data==a->data) return true;

    if(solve(root->left,a,v) or solve(root->right,a,v)) return true;

    v.pop_back();
    return false;

}
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    vector<TreeNode*>a;
    vector<TreeNode*>b;

    if(!solve(root,P,a) or !solve(root,Q,b)){
        return NULL;
    }

    int i=0;
    while(i<a.size()){
        if(a[i]!=b[i]) break;
        i++;
    }

    return a[i-1];
}

t.c:-O(h) and s.c:-O(h) and for skew tree O(n) t.c and s.c okk


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




