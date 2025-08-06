
Code
Test Result
Test Result
Testcase
101. Symmetric Tree
Solved
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?











/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode *a,TreeNode *b){
        if(a==NULL and b==NULL) return true;
        if(a==NULL or b==NULL) return false;

        if(a->val==b->val){
            if(solve(a->left,b->right) and solve(a->right,b->left)) return true;
        }

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};


leetcode 



gfg

Two Mirror Trees
Difficulty: EasyAccuracy: 57.36%Submissions: 41K+Points: 2Average Time: 20m
Given a Two Binary Trees, write a function that returns true if one is mirror of other, else returns false.
MirrorTree1            

Examples:

Input:
a:      1     b:      1
      /   \         /   \
     2     3       3     2
Output: true
Explanation: Given pairs of binary tree are mirror of each other.

Input:
a:      10      b:    10
       /  \          /  \
      20  30        20  30
     /  \          /  \
    40   60       40  60
Output: false
Explanation: Given pairs of binary tree are not mirror of each other.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(h).

Constraints:
1 <= number of nodes<= 105
0 <= node -> data<= 105 



class Solution {
  public:
    bool areMirror(Node* a, Node* b) {
        // Your code here
        if(a==NULL and b==NULL) return true;
        if(!a or !b) return false;
        if(a->data!=b->data) return false;
        
        bool left=areMirror(a->left,b->right);
        bool right=areMirror(a->right,b->left);
        
        if(left and right) return true;
        return false;
    }
};
