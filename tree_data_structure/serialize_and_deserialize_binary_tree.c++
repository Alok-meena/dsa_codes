297. Serialize and Deserialize Binary Tree
Solved
Hard
Topics
premium lock icon
Companies
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000







/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string solve1(TreeNode *root){
        if(root==NULL) return "";

        string res=to_string(root->val);

        if(root->left or root->right){
            res+="("+solve1(root->left)+")";
        }

        if(root->right){
            res+="("+solve1(root->right)+")";
        }

        return res;
    }
    string serialize(TreeNode* root) {
        return solve1(root);
    }

    void solve(TreeNode* &root,string &s,int &i){
        if(i>=s.length() or s[i]==')'){
            i++;
            return;
        }

        int sign=1;
        if(i<s.length() and s[i]=='-'){
            i++;
            sign=-1;
        }

        int sum=0;
        while(i<s.length() and isdigit(s[i])){
            sum*=10;
            sum+=s[i]-'0';
            i++;
        }

        sum*=sign;

        root=new TreeNode(sum);

        if(i<s.length() and s[i]=='('){
            i++;
            solve(root->left,s,i);
        }

        if(i<s.length() and s[i]=='('){
            i++;
            solve(root->right,s,i);
        }

        if(i<s.length() and s[i]==')'){
            i++;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root=NULL;
        int i=0;
        solve(root,data,i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
