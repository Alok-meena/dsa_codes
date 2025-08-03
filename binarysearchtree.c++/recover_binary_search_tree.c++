99. Recover Binary Search Tree
Medium
Topics
premium lock icon
Companies
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
 

Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?









recursive : - t.c:-O(n) and s.c:-O(h) 


class Solution {
public:
    void inorder(TreeNode *root,TreeNode* &first,TreeNode* &middle,TreeNode* &last,TreeNode* &prev){
        if(root==NULL) return;

        inorder(root->left,first,middle,last,prev);

        if(prev!=NULL and (root->val<prev->val)){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else last=root;
        }

        prev=root;

        inorder(root->right,first,middle,last,prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *first=NULL;
        TreeNode *middle=NULL;
        TreeNode *last=NULL;
        TreeNode *prev=NULL;

        inorder(root,first,middle,last,prev);

        if(first and last) swap(first->val,last->val);
        else if(first and middle) swap(first->val,middle->val);
    }
};




optimized O(1) space using morris traversal

void recoverTree(TreeNode* root) {
        TreeNode *first=NULL;
        TreeNode *middle=NULL;
        TreeNode *last=NULL;
        TreeNode *prev=NULL;

        TreeNode *curr=root;

        while(curr!=NULL){
            if(curr->left){
                TreeNode *temp=curr->left;
                while(temp->right!=NULL and temp->right!=curr){
                    temp=temp->right;
                }

                if(temp->right==NULL){
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    temp->right=NULL;
                    if(prev!=NULL and curr->val<prev->val){
                        if(first==NULL){
                            first=prev;
                            middle=curr;
                        }
                        else last=curr;
                    }
                    prev=curr;
                    curr=curr->right;
                }
            }
            else{
                if(prev!=NULL and curr->val<prev->val){
                    if(first==NULL){
                        first=prev;
                        middle=curr;
                    }
                    else last=curr;
                }
                prev=curr;
                curr=curr->right;
            }
        }

        if(first and last) swap(first->val,last->val);
        else if(first and middle) swap(first->val,middle->val);
    }

