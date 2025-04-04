
Code


Testcase
Testcase
Test Result
1123. Lowest Common Ancestor of Deepest Leaves
Solved
Medium
Topics
Companies
Hint
Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
 

Constraints:

The number of nodes in the tree will be in the range [1, 1000].
0 <= Node.val <= 1000
The values of the nodes in the tree are unique.




to is ques me hame lca nikalna hai deepest leaves ka alright so the leaves can be at the same level or diff okk if height of left and right subtree equal then
the root node is the possible lca alright because ager left right subtree ki height same aa rhi hai to dono me hi deepest leaf node hogi bs fir kya dono 
ka lca root node hi hoga alright
  



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
     int height(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        
        int left=height(node->left);
        int right=height(node->right);
        
        int ans=max(left,right)+1;
        return ans;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return root;

        int left=height(root->left);
        int right=height(root->right);

        if(left==right) return root;
        else if(left>right) return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);
    }
};


t.c:-O(n*h) worst case n is the total nodes s.c:-O(h)


in bst t.c:-O(n*logn) 


and if tree is not symmetric if 4 is removed from above example then this code may not work so we have to use postorder like this 

 class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.first == right.first) return {left.first + 1, root};
        return left.first > right.first ? make_pair(left.first + 1, left.second)
                                        : make_pair(right.first + 1, right.second);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};




and this is the same code for smallest subtree with all the deepest leaves alright same ditto code


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
    int height(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        
        int left=height(node->left);
        int right=height(node->right);
        
        int ans=max(left,right)+1;
        return ans;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL) return root;

        int left=height(root->left);
        int right=height(root->right);

        if(left==right) return root;
        else if(left>right) return subtreeWithAllDeepest(root->left);
        else return subtreeWithAllDeepest(root->right);
    }
};
