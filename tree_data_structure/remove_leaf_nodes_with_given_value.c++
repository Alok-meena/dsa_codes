1325. Delete Leaves With a Given Value
Solved
Medium
Topics
Companies
Hint
Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

 

Example 1:



Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
Example 2:



Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]
Example 3:



Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.






class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL){
            return root;
        }

      //aor nodes return ho rhi to left and right ko point bhi krvana hai okk

        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);

        //yha mene kya glti ki ki last tk traversse kre bina hi me check krna start kr diya tha which is wrong when returning from there then we can also check
      // if root is null or not okk then check the condition

        if(root->left==NULL and root->right==NULL and root->val==target){
            return NULL;
        }

        return root;
    }
};

t.c:-O(n) and s.c:-O(h) worst O(n)
