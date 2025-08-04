Leaves at Same Level or Not
Difficulty: EasyAccuracy: 39.47%Submissions: 128K+Points: 2
Given a binary tree with n nodes, determine whether all the leaf nodes are at the same level or not. Return true if all leaf nodes are at the same level, and false otherwise.

Examples :

Input: root = [1, 2, 3]
    1
   / \
  2   3
Output: true
Explanation: The binary tree has a height of 2 and the leaves are at the same level.
Input: root = [10, 20, 30, 10, 15, N, N]
    10
   /  \
 20   30
 /  \
 10   15
Output: false
Explanation: The binary tree has a height of 3 and the leaves are not at the same level.
Input: root = [3, 2, 1]
    3
   / \
  2   1
Output: true
Explanation: The binary tree has a height of 2 and the leaves are at the same level.
Constraints:
1 ≤ n ≤ 105










class Solution {
  public:
    /*You are required to complete this method*/
    int height(Node *root){
        if(root==NULL) return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        
        return max(left,right)+1;
    }
    
    bool solve(Node *root,int len,int cnt){
        if(root==NULL) return true;
        
        if(root->left==NULL and root->right==NULL){
            return cnt==len;
        }
        
        bool left=solve(root->left,len,cnt+1);
        bool right=solve(root->right,len,cnt+1);
        
        return left and right;
    }
    bool check(Node *root) {
        // Your code here
        int len=height(root);
        
        int cnt=1;
        
        return solve(root,len,cnt);
    }
};


best

class Solution {
  public:
    /*You are required to complete this method*/
    bool check(Node *root) {
        // Your code here
        queue<pair<int,Node*>>q;
        q.push({0,root});
        
        int leaflevel=0;
        bool first=true;
        
        while(!q.empty()){
            int level=q.front().first;
                Node *front=q.front().second;
                q.pop();
                
                if(front->left==NULL and front->right==NULL){
                    if(!first and level!=leaflevel) return false;
                    leaflevel=level;
                    first=false;
                }
                
                if(front->left){
                    q.push({level+1,front->left});
                }
                if(front->right){
                    q.push({level+1,front->right});
                }
        }
        
        return true;
    }
};

t.c:-O(n) and s.c:-O(max nodes at level)
