Given a binary search tree which is also a complete binary tree.
The problem is to convert the given BST into a Min Heap with the
condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node.
This condition is applied to all the nodes, in the resultant converted Min Heap. 


void inorder(BinaryTreeNode*root,vector<int>&ans){
	if(root==NULL){
		return;
	}
	inorder(root->left,ans);
	ans.push_back(root->data);
	inorder(root->right,ans);
}

void preorder(BinaryTreeNode*root,int &index,vector<int>&ans){ //bs inorder ki values store kra li then preorder lgaya aor values ko tree me replace krte gye
  // because we want N<L<R that is pre order 
	if(root==NULL){
		return;
	}

	root->data=ans[index++];
	preorder(root->left,index,ans);
	preorder(root->right,index,ans);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	vector<int>ans;
	inorder(root,ans);

	int index=0;
	preorder(root,index,ans);

	return root;
}

Time Complexity
O(N), where ‘N’ is the number of nodes in the given tree.

 

Since we are traversing all the nodes of the tree, therefore O(N).

Space Complexity
O(N), where ‘N’ is the number of nodes in the given tree.

 

Since we are using an array to store all the nodes of the tree, therefore O(N).




