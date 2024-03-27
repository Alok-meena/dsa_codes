Brute-Force Approach
Note that the inorder traversal of a BST is always sorted.
So, we can traverse the BST in an inorder manner and store the values in an array.
Then we create a new node for each element in the array, make its left child NULL and right child equal to the node containing the next element in the array.
For the last element, we make both the left and right child NULL.

Time Complexity
O(N), where ‘N’ is the number of nodes in the given BST.

 

We are traversing the BST only once to store all the values in the array after the inorder traversal.
Then, we traverse the array one more time to create the flattened list. Hence, the overall time complexity is O(N).

Space Complexity
O(N), where ‘N’ is the total number of nodes in the given BST.

 

We are storing the values of all the nodes in an array after the inorder traversal. Hence, the overall space complexity will be O(N).



void inorder(TreeNode<int>* root,vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int>in;
    inorder(root,in);

    int n=in.size();

    TreeNode<int>* newroot=new TreeNode<int>(in[0]);//root ko first sorted value de di 
    TreeNode<int>* curr=newroot;curr rkha to traverse it
    for(int i=1;i<n;i++){
        TreeNode<int>* temp=new TreeNode<int>(in[i]);//ye bnaya to enter the value
        curr->left=NULL;// then bs right ko next value pe pont krvate jao and left ko null aor current ko bhi temp pe update krte jao
        curr->right=temp;
        curr=temp;
    }

    curr->left=NULL;// at last last node ke left and right dono ko Null kr do
    curr->right=NULL;

    return newroot;
}
t.c:-O(N)
s.c:-O(N)
