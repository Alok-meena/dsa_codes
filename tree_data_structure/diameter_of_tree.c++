
#approach 1: but it will include T.C:-O(N2)

#include <algorithm>
class Solution {
    private:
      int height(Node* node){
        if(node==NULL){
            return 0;
        }
        
        int left=height(node->left);
        int right=height(node->right);
        
        int ans=max(left,right)+1;
        return ans;
    }
    
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        
        int a1=diameter(root->left);
        int a2=diameter(root->right);
        int a3=height(root->left)+1+height(root->right);
        int ans=max(a1,max(a2,a3));
        return ans
    }
};

#approach 2 : using pair <int,int> .... first is diameter and second value is height ..........

#include <algorithm>
class Solution {
    private:
      int height(Node* node){
        if(node==NULL){
            return 0;
        }
        
        int left=height(node->left);
        int right=height(node->right);
        
        int ans=max(left,right)+1;
        return ans;
    }
    pair<int,int> diameterFast(Node *root){
        //base case
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        
        pair<int,int>left=diameterFast(root->left);
        pair<int,int>right=diameterFast(root->right);
        
        
        int a1=left.first;
        int a2=right.first;
        int a3=left.second + right.second + 1;
        
        pair<int,int>ans;
        ans.first=max(a1,max(a2,a3));
        ans.second=max(left.second,right.second)+1;
        
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        
        
        return diameterFast(root).first;
    }
};
