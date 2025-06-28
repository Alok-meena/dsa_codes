
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int pre=-1;
    int succ=-1;
    TreeNode *temp=root;

    while(temp){
        if (temp->data == key) break;
        else if (temp->data < key) {
            pre = temp->data; // potential predecessor because right me ja rhe to ye chota hai to pre possible hai same for below dry run and understand alright
            temp = temp->right;
        } else {
            succ = temp->data; // potential successor
            temp = temp->left;
        }
    }

    if(temp==NULL) return {pre,succ};

    TreeNode *pred=temp->left;
    while(pred){
        pre=pred->data;
        pred=pred->right;
    }

    TreeNode *successor=temp->right;
    while(successor){
        succ=successor->data;
        successor=successor->left;
    }

    return {pre,succ};
}
t.c:-O(N)
s.c:-O(1)


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


best approach :------------





pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int pred=-1;
    int succ=-1;

    TreeNode *curr=root;
    while(curr and curr->data!=key){
         
        if(curr->data>key){
            succ=curr->data;
            curr=curr->left;
        }
        else{
            pred=curr->data;
            curr=curr->right;
        }
    }

    if(curr){
        //find pred (max from left subtree)
        TreeNode *p=curr->left;
        while(p!=NULL){ //here we cant have p->right!=NULL condition as what if curr->left is null then it will give segmentation fault okk alright
            pred=p->data;
            p=p->right;
        }

        //find succ (min from right)
        TreeNode *s=curr->right;
        while(s!=NULL){
            succ=s->data;
            s=s->left;
        }
    }

    return {pred,succ};
}

this is the correct code of taking care of null exceptions and all okk

t.c:-O(n) and s.c:-O(1)


and using vector below is the code


void inorder(TreeNode* root,vector<int>&ans){
    if(root==NULL) return;

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    vector<int>ans;
    inorder(root,ans);
    int n=ans.size();

    int pre=-1;
    int succ=-1;

    for(int i=0;i<n;i++){
        if(ans[i]<key){
            pre=ans[i];
        }
        else break;
    }

    for(int i=n-1;i>=0;i--){
        if(ans[i]>key){
            succ=ans[i];
        }
        else break;
    }

    return {pre,succ};
}

t.c:-O(n) and s.c:-O(n)

i did mistake as if the element is not present then also we have to return the ans so what is pred just smaller and succ just greater so update continuosly the ans
