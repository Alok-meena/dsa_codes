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

t.c:-O(n) and s.c:-O(n)

or can do it directly without storing in vector



int solve(BinaryTreeNode<int>*root,int &i,int k){
    if(root==NULL){
        return -1;
    }
    int left=solve(root->left,i,k);

    //are bhai ye bs isliye kiya taki function khuch to return kre apna
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

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i=0;
    BinaryTreeNode<int>* curr=root;    

    while(curr!=NULL){
            if(curr->left!=NULL){
                BinaryTreeNode<int> *temp=curr->left;
                while(temp->right!=NULL and temp->right!=curr){
                    temp=temp->right;
                }
                if(temp->right==NULL){
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    temp->right=NULL;
                    i++;
                     if(i==k) return curr->data;
                    curr=curr->right;
                }
            }
            else{
                i++;
                if(i==k) return curr->data;
                curr=curr->right;
            }
        }
        
        return -1;
}

and for kth largest element just one change n-k+1 th smallest element okk
