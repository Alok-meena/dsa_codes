You have been given a Binary Search Tree and a target value.
You need to find out whether there exists a pair of node values in the BST, such that their sum is equal to the target value.

A binary search tree (BST), also called an ordered or sorted binary tree,
is a rooted binary tree whose internal nodes each store a value greater than all the values keys in the node's left subtree and less than those in its right subtree.

Follow Up:
Can you solve this in O(N) time, and O(H) space complexity?

approach 1:- 

brute force :-
take any node data then do (target-nodedata) and call for left or right part if equals any vaue

approach 2:- 

  
// to khuch nhi kiya pahle inorder traversal ko save kra liya 
void inorder(BinaryTreeNode<int>* root,vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int>in;
    inorder(root,in);

    int i=0;
    int j=in.size()-1;
    // then we have used two pointer concept in the vector containing elements
    while(i<j){
        int sum=in[i]+in[j];
        if(sum==target){
            return true;
        }
        // ager sum=target ho gya to return true otherwise if sum>target to  mtlb value km kro to j-- karna becaues i to pahle hi km value pe h 
        // and second case me just do reverse of it
        else if(sum>target){
            j--;
        }
        else if(sum<target){
            i++;
        }
    }
    return false;

}

t.c:-O(N) // O(N) for the traversal of each node and O(N) for the traversal of the vector --O(N)
s.c:-O(H) and O(N) in skewed tree it is due to recursive calls can use morris inorder traversal for O(1) time complexity
