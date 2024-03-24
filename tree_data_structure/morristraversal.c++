Inorder Tree Traversal without recursion and without stack!
 
Using Morris Traversal, we can traverse the tree without using stack and recursion. 
The idea of Morris Traversal is based on Threaded Binary Tree.
In this traversal, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore original tree. 

1. Initialize current as root 
2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Find rightmost node in current left subtree OR
              node whose right child == current.
         If we found right child == current
             a) Update the right child as NULL of that node whose right child is current
             b) Print current’s data
             c) Go to the right, i.e. current = current->right
         Else
             a) Make current as the right child of that rightmost 
                node we found; and 
             b) Go to this left child, i.e., current = current->left
Although the tree is modified through the traversal, it is reverted back to its original shape after the completion.
Unlike Stack based traversal, no extra space is required for this traversal.

a). Inorder Morris Traversal:-

void morristraversal(node *root){ 
    // to sbse pahle current se start kro jb tk null na ho ager current ka left null h to print current data and move it to the right part because it is NULL
    // nhi to precdecessor nikalo mtlb ek left then right jate jao jab tak NULL na ho jaye aor not equal to current also then pahuchte hi pre ke right ko
    // current ke equal and curr ko left pe le jao but if null nhi hua to mtlb pre ka next curr ke equal hai to pre ke next ko NULL kr do print curr data and then 
    // move current to the right part ....
    node *current;
    node *predecessor;
    if(root==NULL){
        return;
    }
    current=root;
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->data<<" ";
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
                cout<<current->data<<" ";
                current=current->right;
            }
        }
    }
}










Time Complexity: O(n)

If we take a closer look,
we can notice that every edge of the tree is traversed at most three times.
And in the worst case, the same number of extra edges (as input tree) are created and removed.
  
Auxiliary Space: O(1) since using only constant variables



Threaded binary tree:---

A threaded binary tree is a type of binary tree data structure where the empty
left and right child pointers in a binary tree are replaced with threads that link nodes directly to their in-order predecessor or successor,
thereby providing a way to traverse the tree without using recursion or a stack.

Threaded binary trees can be useful when space is a concern, as they can eliminate the need for a stack during traversal. 
However, they can be more complex to implement than standard binary trees.

There are two types of threaded binary trees. 
Single Threaded: Where a NULL right pointers is made to point to the inorder successor (if successor exists)
Double Threaded: Where both left and right NULL pointers are made to point to inorder predecessor and inorder successor respectively.
The predecessor threads are useful for reverse inorder traversal and postorder traversal.




b). Morris Traversal for pre-order   

  // Preorder traversal without recursion and without stack  
void morrisTraversalPreorder(node* root)  
{  
    while (root)  
    {  
        // If left child is null, print the current node data. Move to  
        // right child.  
        if (root->left == NULL)  
        {  
            cout<<root->data<<" ";  
            root = root->right;  
        }  
        else
        {  
            // Find inorder predecessor  
            node* current = root->left;  
            while (current->right && current->right != root)  
                current = current->right;  
  
            // If the right child of inorder predecessor already points to  
            // this node  
            if (current->right == root)  
            {  
                current->right = NULL;  
                root = root->right;  
            }  
  
            // If right child doesn't point to this node, then print this  
            // node and make right child point to this node  
            else
            {  
                cout<<root->data<<" ";  
                current->right = root;  
                root = root->left;  
            }  
        }  
    }  
}  


c). for post order:-

  


