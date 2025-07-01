Construct Binary Tree from String with bracket representation
Difficulty: MediumAccuracy: 59.15%Submissions: 23K+Points: 4
Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the roots value and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists. The integer values will be less than or equal to 10^5.

Example 1:

Input: "1(2)(3)" 
Output: 2 1 3
Explanation:
           1
          / \
         2   3
Explanation: first pair of parenthesis contains 
left subtree and second one contains the right 
subtree. Inorder of above tree is "2 1 3".
Example 2:

Input: "4(2(3)(1))(6(5))"
Output: 3 2 1 4 5 6
Explanation:
           4
         /   \
        2     6
       / \   / 
      3   1 5   
Your Task:
You don't need to read input or print anything. Your task is to complete the function treeFromString() which takes a string str as input parameter and returns the root node of the tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)














t.c O(n) and s.c O(h)

this code will work in bst also alright


class Solution {
  public:
    void solve(Node* curr,Node *&prev){
        if(curr==NULL) return;
        
        solve(curr->left,prev);
        
        prev->right=curr;
        curr->left=prev;
        prev=curr;
        
        solve(curr->right,prev);
    }
    Node* bToDLL(Node* root) {
        // code here
        Node *dummy=new Node(-1);
        Node *prev=dummy;
        
        solve(root,prev);
        
        prev->right=NULL;
        Node *newroot=dummy->right;
        newroot->left=NULL;
        
        return newroot;
    }
};

simple and efficient , this approach is taken from bst to sorted list approach alright
