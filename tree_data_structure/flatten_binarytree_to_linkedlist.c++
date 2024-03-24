Given the root of a binary tree, flatten the tree into a "lLinked list":

The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example 1:

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 

Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.




approach 1:----

class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node *curr=root;
        while(curr!=NULL){
            if(curr->left){
                Node *pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;// because in ques mentioned that curr ke left koo null krte rhna
            }
            curr=curr->right;
        }
        // curr=root;
        // while(curr!=NULL){
        //     curr->left=NULL;
        //     curr=curr->right;
        // }
        
    }
};


approach 2:- to make left part NULL also
class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node *curr=root;
        while(curr!=NULL){
            if(curr->left){
                Node *pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
            }
            curr=curr->right;
        }
        curr=root;
        while(curr!=NULL){
            curr->left=NULL;
            curr=curr->right;
        }
        
    }
};
