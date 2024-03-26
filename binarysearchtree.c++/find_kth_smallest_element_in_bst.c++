approach 1:- using a vector 

void inorder(BinaryTreeNode<int>* root, vector<int>& inTraversal)
{
	if (root == NULL)
	{
		return;
	}

	// Recurse over left subtree. 
	inorder(root -> left, inTraversal);

    inTraversal.push_back(root -> data);

	// Recurse over right subtree.
	inorder(root -> right, inTraversal);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    // int i=1;
    // return morristraversal(root,k,i);

    vector <int> inTraversal;

	inorder(root, inTraversal);

	int n = inTraversal.size();

	if (k > n)
	{
		return -1;
	}
	
	return inTraversal[k-1];// k-1 if 0 based indexing is there
   
}



int solve(BinaryTreeNode<int>*root,int &i,int k){
    if(root==NULL){
        return -1;
    }
    int left=solve(root->left,i,k);
    if(left!=-1){// ager left -1 nhi h to hi return kro nhi to rhne do and i ka track rkha so bi reference pass kiya ise to reach to k
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right,i,k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}

t.c:-O(N)
s.c:-O(H)



approach 2 : using morris traversal then s.c:- O(1) 

int morristraversal(BinaryTreeNode<int>* root, int k,int &i){
    if(root==NULL){
        return -1;
    }
     BinaryTreeNode<int>*current=root;
    BinaryTreeNode<int>*predecessor=NULL;
    while(current!=NULL){
        if(current->left==NULL){
            if(i++==k){
                return current->data;
            }
            current=current->right;
        }
        else{
            predecessor=current->left;
            while(predecessor->right!=NULL && predecessor->right!=current){
                predecessor=predecessor->right;
            }
            if(predecessor->right==NULL){
                predecessor->right=current;
                current=current->left;
            }
            else{
                predecessor->right=NULL;
                if(i++==k){
                    return current->data;
                }
                current=current->right;
            }
        }
    }
    return -1;
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i=1;// if u will take i=0 then compare it with k-1 not with k
    return morristraversal(root,k,i);
   
}
