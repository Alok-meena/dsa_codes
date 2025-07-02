Binary Tree to BST
Difficulty: EasyAccuracy: 60.75%Submissions: 80K+Points: 2
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 Example 1:

Input:
      1
    /   \
   2     3
Output: 
1 2 3
Explanation:
The converted BST will be 
      2
    /   \
   1     3

Example 2:

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 
1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1
Your Task:
You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input and returns the root of the BST. The driver code will print inorder traversal of the converted BST.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105








class Solution {
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder(Node* root,vector<int>&v){
        if(root==NULL) return;
        
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
  
    
    void fun(Node* root,vector<int>&in,int &idx){
        if(root==NULL) return ;

        //bilkul correct order hai inorder me hi;
        fun(root->left,in,idx);
        root->data=in[idx++];
        fun(root->right,in,idx);
    }
    Node *binaryTreeToBST(Node *root) {
        // Your code goes here
        vector<int>in;
        inorder(root,in);
        
        sort(in.begin(),in.end());
        
        int idx=0;
        
        fun(root,in,idx);
        return root;
    }
};

t.C:-O(N) and s.c:-O(n) alright bs khuch nhi inorder store krke sam structure me replace kr diya that's it
