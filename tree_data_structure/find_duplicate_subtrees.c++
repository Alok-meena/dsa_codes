Duplicate Subtree
Difficulty: MediumAccuracy: 34.23%Submissions: 103K+Points: 4
Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one. 

Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
Example 2 :

Input : 
               1
             /   \ 
           2       3
Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function dupSub() which takes root of the tree as the only argument and returns 1 if the binary tree contains a duplicate sub-tree of size two or more, else 0.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

Constraints:
0 ≤ Data of nodes ≤ 12
1 ≤ Number of nodes ≤ 105 








class Solution {
  public:
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    string solve(Node* root,unordered_map<string,int> &mp){
        if(root == NULL) return "N";
        if(root->left == NULL && root->right == NULL){
            string s = to_string(root->data);
            return s;
        }
        string s = to_string(root->data) + "," + solve(root->left,mp) + "," + solve(root->right,mp);
        mp[s]++;
        return s;
    }
    int dupSub(Node *root) {
         unordered_map<string,int> mp;
         solve(root,mp);
         for(auto i:mp){
             if(i.second > 1) return 1;
         }
         return 0;
    }
};


t.c:-O(n^2) and s.c:-O(n) 

due to string creation at each node alright as concatenation has O(n) t.c alright 
