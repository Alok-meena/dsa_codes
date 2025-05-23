
firstly height for edges

  int height(Node* node) {
        // code here
        if(node==NULL){
            return -1;//as edges are one less than the nodes
        }
        
        int leftheight=height(node->left);
        int rightheight=height(node->right);
        int totalH=max(leftheight,rightheight)+1;
        return totalH;
    }

now diameter 

fisrt approach

class Solution {
  public:
  //here we have to count the height normally not by edge method
  int height(Node* node) {
        // code here
        if(node==NULL){
            return 0;
        }
        
        int leftheight=height(node->left);
        int rightheight=height(node->right);
        int totalH=max(leftheight,rightheight)+1;
        return totalH;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // code here
        if(root==NULL) return 0;
        
        int op1=diameter(root->left);
        int op2=diameter(root->right);
        int op3=height(root->left)+height(root->right);
        return max(op1,max(op2,op3));
    }
};
t.c:-O(n^2) due to func call stack
optimized
class Solution {
  public:
  pair<int,int> Diameter(Node *root){
      if(root==NULL){
          pair<int,int>p=make_pair(0,0);
          return p;
      }
      
      pair<int,int> left=Diameter(root->left);
      pair<int,int> right=Diameter(root->right);
      
      int o1=left.first;
      int o2=right.first;
      int o3=left.second+right.second;//this for diameter okk
      
      pair<int,int>ans;
      ans.first=max(o1,max(o2,o3));
      ans.second=max(left.second,right.second)+1; //ye hamne kiya to store the normal height of the tree 
      return ans;
  }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // code here
        return Diameter(root).first;
    }
};


and the smallest code 

class Solution {
public:
    int solve(TreeNode *root,int &ans){
        if(root==NULL){
            return 0;
        }

        int lh=solve(root->left,ans);
        int rh=solve(root->right,ans);

        int currd=lh+rh;
        ans=max(ans,currd);

        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int a=solve(root,ans);
        return ans;
    }
};

just do +1 in the currdiameter if nodes are considered instead of these edges okk

(bs khuch nhi curr node pe khde hai aor left ki height aor right ki height ko add kr rhe hai aor +1 nhi kiya for edges and ager ye cheez uper 
bhej rhe hai to curr node ka bhi count krna hai that's why +1 )
