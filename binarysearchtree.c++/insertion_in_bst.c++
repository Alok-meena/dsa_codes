

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode *temp=new TreeNode(val);
            return temp;
        }

        if(root->val>val){
            root->left=insertIntoBST(root->left,val);
        }
        else{
            root->right=insertIntoBST(root->right,val);
        }

        return root;
    }
};

this is our recursive approach so t.c and s.c is O(h) and in worst case it would be O(n) 

iterative approach :---

t.c:-O(height) or O(n) in worst case and s.c:-O(1)

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode *temp=new TreeNode(val);
            return temp;
        }

        TreeNode *curr=root;
        while(curr!=NULL){
            if(curr->val<=val){
                if(curr->right){
                    curr=curr->right;
                }
                else{
                    TreeNode *temp=new TreeNode(val);
                    curr->right=temp;
                    break;
                }
            }
            else{
                if(curr->left){
                    curr=curr->left;
                }
                else{
                    TreeNode *temp=new TreeNode(val);
                    curr->left=temp;
                    break;
                }
            }
        }

        return root;
    }
};

nothing bs ager shi node pe pahuch gye aor agla null hai to node insert kro aor bhago loop se aor kya
