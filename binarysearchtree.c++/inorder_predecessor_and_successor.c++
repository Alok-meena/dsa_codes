pair<int, int> predecessorSuccessor(TreeNode *root, int key){
    TreeNode *temp=root;

    int pre=-1;
    int succ=-1;

    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pre=temp->data;
            temp=temp->right;
        }
    }

    TreeNode * leftsubtree=temp->left;
    while(leftsubtree!=NULL){
        pre=leftsubtree->data;
        leftsubtree=leftsubtree->right;
    }

    TreeNode *rightsubtree=temp->right;
    while(rightsubtree!=NULL){
        succ=rightsubtree->data;
        rightsubtree=rightsubtree->left;
    }

    pair<int,int>ans=make_pair(pre,succ);
    return ans;
} 

don't know why this code cause tle for some cases....

// to inorder pre hoga left subtree me se max value and inorder successor is min value from right subtree



appraoch 2:----

    
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int predecessor = -1;
    int successor = -1;

    // Initializing temporary node with head.
    TreeNode *temp = root;

    // Traversing in tree.
    while (temp != NULL)
    {
        if (key > temp->data)
        {
            // Updating predecessor.
            predecessor = temp->data;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    temp = root;

    // Traversing in tree.
    while (temp != NULL)
    {
        if (key >= temp->data)
        {
            temp = temp->right;
        }
        else
        {
            // Updating successor.
            successor = temp->data;
            temp = temp->left;
        }
    }

    return make_pair(predecessor, successor);
}

Time Complexity
O(N),  where ‘N’ is the number of nodes in the BST.

In the worst case(skewed tree), we will have to traverse all the nodes in the BST. Hence the time complexity will be O(N).

Space Complexity
O(1), i.e. we are using constant space.

We are not using any extra space. Hence, the space complexity is constant.


approach 2:-


    
INORDER TRAVERSAL
The fact that all the data values are unique makes the solution look very intuitive.
We can simply store the inorder traversal of the given tree in the array, and find the element present before and after the given node in the array.
For every node, its left subtree is visited recursively, and then the node itself is visited(the data is stored in the array), and then its right subtree.
After the traversal, we can find the given node in the inorder array and return its predecessor and successor, if any.
Time Complexity
O(N),  where ‘N’ is the number of nodes in the BST.

 

As we are traversing each node of the BST once, the time complexity will be linear.

Space Complexity
O(N), where ‘N’ is the number of nodes in the BST.

 

In the worst case (skewed trees), we will have all the nodes of the BST in the recursion stack. 

Also, the maximum possible size of the array used to store inorder traversal will be equal to N. Hence, the space complexity is linear.



void inorder(TreeNode *root, vector<int> &inorderArray)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, inorderArray);

    inorderArray.push_back(root->data);

    inorder(root->right, inorderArray);
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // To store the inorder traversal of the BST.
    vector<int> inorderArray;

    inorder(root, inorderArray);

    int predecessor = -1, successor = -1;

    // Finding predecessor.
    for (int i = 0; i < inorderArray.size(); i++)
    {
        if (inorderArray[i] < key)
        {
            predecessor = inorderArray[i];
        }
    }

    // Finding successor.
    for (int i = inorderArray.size() - 1; i >= 0; i--)
    {
        if (inorderArray[i] > key)
        {
            successor = inorderArray[i];
        }
    }

    // We are returning here.
    return {predecessor, successor};
}
