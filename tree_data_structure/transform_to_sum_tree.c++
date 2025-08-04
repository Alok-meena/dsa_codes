Transform to Sum Tree
Difficulty: EasyAccuracy: 70.5%Submissions: 76K+Points: 2
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
 

Your Task:  
You dont need to read input or print anything. Complete the function toSumTree() which takes root node as input parameter and modifies the given tree in-place.

Note: If you click on Compile and Test the output will be the in-order traversal of the modified tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 104



  




brute force: 

storing each root node and computing left and right sum alright 

t.c:-O(n) and s.c:-O(n)+O(h) == O(n) due to map and recursive stack alright



class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    Node* solve(Node* &node,unordered_map<Node*,int>&m){
        if(node==NULL) return NULL;
        
        if(node!=NULL) m[node]=node->data;
        
        Node* left=solve(node->left,m);
        Node* right=solve(node->right,m);
        
        node->data=(left!=NULL?left->data:0) + 
                   (right!=NULL?right->data:0) +m[left]+m[right];
        
        return node;
        
        
    }
    void toSumTree(Node *node) {
        // Your code here
        unordered_map<Node*,int>m;
        
        node=solve(node,m);
    }
};


more space optimzied O(h) 


class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node* &root){
        if(root==NULL) return 0;
        
        int oldvalue=root->data;
        
        int left=solve(root->left);
        int right=solve(root->right);
        
        root->data=left+right;
        
        return root->data+oldvalue;
    }
    void toSumTree(Node *node) {
        // Your code here
        int v=solve(node);
    }
};

isme bs ham oldvalue store kr rhe hai alright har ek level ki 


or 

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    pair<int,int> solve(Node* &root){
        if(root==NULL) return {0,0};
        
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        pair<int,int>ans;
        
        int sum=left.second+right.second;
        
        ans.first=root->data;
        ans.second=sum+root->data;
        
        root->data=sum;
        
        return ans;
    }
    void toSumTree(Node *node) {
        // Your code here
        solve(node);
    }
};
