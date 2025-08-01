1373. Maximum Sum BST in Binary Tree
Solved
Hard
Topics
premium lock icon
Companies
Hint
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:



Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
Example 2:



Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
 

Constraints:

The number of nodes in the tree is in the range [1, 4 * 104].
-4 * 104 <= Node.val <= 4 * 104









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


t.c:-O(n) and s.c:-O(h)  alright


class Solution {
public:
    class isbst{
        public:
        bool ISbst;
        int maxi;
        int mini;
        int sum;
    };

    isbst solve(TreeNode *root,int &maxi){
        if(root==NULL) return {true,INT_MIN,INT_MAX,0};

        isbst left=solve(root->left,maxi);
        isbst right=solve(root->right,maxi);

        if(left.ISbst and right.ISbst and root->val>left.maxi and root->val<right.mini){
            int currsum=left.sum+right.sum+root->val;
            maxi=max(maxi,currsum);
            return {true,max(right.maxi,root->val),min(left.mini,root->val),currsum};
        }

        return {false,0,0,0};
    }
    int largestsum(TreeNode * root){
        // Write your code here.
        int maxi=0;
        solve(root,maxi);
        return maxi;
    }
    int maxSumBST(TreeNode* root) {
        return largestsum(root);
    }
};
