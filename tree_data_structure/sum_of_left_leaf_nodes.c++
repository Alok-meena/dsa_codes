
Code
Test Result
Testcase
Testcase
404. Sum of Left Leaves
Solved
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000






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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        queue<pair<TreeNode*,bool>>q;
        q.push({root,false});

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *front=q.front().first;
                bool isleft=q.front().second;
                q.pop();

                if(isleft and front->left==NULL and front->right==NULL){
                    sum+=front->val;
                }

                if(front->left) q.push({front->left,true});
                if(front->right) q.push({front->right,false});
            }
        }
        
        return sum;
    }
};
