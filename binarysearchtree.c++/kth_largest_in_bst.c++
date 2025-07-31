morris traversal is not possible in this case

nhi bhai possible hai look


class Solution {
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
      int i=0;
    int ans=-1;
    Node * curr=root;

    while(curr!=NULL){
        if(curr->right){
            Node* temp=curr->right;
            while(temp->left!=NULL and temp->left!=curr){
                temp=temp->left;
            }

            if(temp->left==NULL){
                temp->left=curr;
                curr=curr->right;
            }
            else{
                i++;
                if(i==k) ans=curr->data;
                temp->left=NULL;
                curr=curr->left;
            }
        }
        else{
            i++;
            if(i==k) ans=curr->data;
            curr=curr->left;
        }
    }

    return ans;
    }
};

t.c:-O(n) and s.c:-O(1)


void rec(TreeNode<int>*root,int& k,int &cnt,int &ans)
{
   if (root==NULL) return ;
   rec(root->right,k,cnt,ans);// bs khuch nhi kiya pahle inorder traversal me right part ko call kiya jo ki us part ke kth smallest element ko access kr liya
   cnt++;
   if (cnt==k) ans=root->data;
   rec(root->left,k,cnt,ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans=-1;
    int cnt=0;
    rec(root,k,cnt,ans);
    return ans;
}


same approach as in smallest element is reverse inorder traversal which is shown above also and another visualization of the same is:---

int revInorder(TreeNode<int>* root, int &visCount, int k)
{
	if (root == NULL)
	{
		return -1;
	}
	
	// Recurse over right subtree. 
	int right = revInorder(root -> right, visCount, k);
    
    if (right != -1)
    {
    	return right;
    }

	visCount++;

	if (visCount == k)
	{
		return root -> data;
	}

	// Recurse over left subtree.
	return revInorder(root -> left, visCount, k);
    
}


int KthLargestNumber(TreeNode<int>* root, int k)
{
	int visCount = 0;

	return revInorder(root, visCount, k);
}

Time Complexity
O(N), where ‘N’ denotes the number of nodes in the BST.

As every node will be visited exactly once in the Inorder Traversal, the time complexity will be O(N).

Space Complexity
O(N), where ‘N’ denotes the number of nodes in the BST.

As the maximum height of the BST can be ‘N’, the space complexity due to the recursion stack will be O(N)


approach 2:--

Inorder Traversal
We can store all the elements of the BST in ascending order in an array/list with the help of one inorder traversal.
We can then return the K-th largest element from it.


void inorder(TreeNode<int>* root, vector<int>& inTraversal)
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


int KthLargestNumber(TreeNode<int>* root, int k)
{
	vector <int> inTraversal;

	inorder(root, inTraversal);

	int n = inTraversal.size();// n is calculate using the size of the vector 

	if (k > n)
	{
		return -1;
	}
	
	return inTraversal[n - k]; // so n-k is the largest element if it is 0 based indexing then n-k+1 will be the largest
}

Time Complexity
O(N), where ‘N’ denotes the number of nodes in the BST.

As every node will be visited exactly once in the Inorder Traversal, the time complexity will be O(N).

Space Complexity
O(N), where ‘N’ denotes the number of nodes in the BST.

As the maximum height of the BST can be ‘N’ and we are storing each node in the vector which has O(N) space complexity,
the space complexity due to the recursion stack and storing nodes in vector will be O(N).
