
Populate Inorder Successor for all nodes
Difficulty: MediumAccuracy: 51.2%Submissions: 57K+Points: 4
Given a Binary Tree, complete the function to populate the next pointer for all nodes. The next pointer for every node should point to the Inorder successor of the node.
You do not have to return or print anything. Just make changes in the root node given to you.

Note: The node having no in-order successor will be pointed to -1. You don't have to add -1 explicitly, the driver code will take care of this.

Examples :

Input:
       10
       /  \
      8   12
     /
    3
Output: 3->8 8->10 10->12 12->-1
Explanation: The inorder of the above tree is : 3 8 10 12. So the next pointer of node 3 is pointing to 8 , next pointer of 8 is pointing to 10 and so on.And next pointer of 12 is pointing to -1 as there is no inorder successor of 12.
Input:
       1
      /  
     2 
   /
 3  
Output: 3->2 2->1 1->-1
Explanation: The inorder of the above tree is: 3 2 1. So the next pointer of node 3 is pointing to 2 , next pointer of 2 is pointing to 1. And next pointer of 1 is pointing to -1 as there is no inorder successor of 1.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(logn)

Constraints:
1<= no. of nodes <=105
1<= data of the node <=105












ooye mtlb ki har node ke next ko uske inorder succ se connect kro like below

t.c:-O(n) and s.c:-O(h) == logn if balanced tree n if skew tree

class Solution {
  public:
  
    void solve(Node* &root,Node *&prev){
        if(root==NULL) return ;
        
        solve(root->left,prev);
        
        prev->next=root;
        prev=root;
        
        solve(root->right,prev);
    }
    void populateNext(Node *root) {
        // code here
        Node *dummy=new Node(-1);
        Node *prev=dummy;
        solve(root,prev);
        
        root=dummy->right;
    }
};
