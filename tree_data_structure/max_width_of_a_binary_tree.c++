
Code
Test Result
Testcase
Testcase
662. Maximum Width of Binary Tree
Solved
Medium
Topics
premium lock icon
Companies
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100








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
    int solve(TreeNode* root){
        queue<pair<long long,TreeNode*>>q;
        long long maxwidth=0;

        q.push({0,root});

        while(!q.empty()){
            long long mini=q.front().first;
            long long maxi=q.back().first;
            maxwidth=max(maxwidth,maxi-mini+1);

            int size=q.size();

            for(int i=0;i<size;i++){
                TreeNode *front=q.front().second;
                long long idx=q.front().first;
                q.pop();

                idx-=mini;

                if(front->left) q.push({2*idx,front->left});
                if(front->right) q.push({2*idx+1,front->right});
            }
        }

        return maxwidth;
    }
    int widthOfBinaryTree(TreeNode* root) {
        return solve(root);
    }
};

t.c:-O(n) and s.c:-O(w) where w is max width of the tree
