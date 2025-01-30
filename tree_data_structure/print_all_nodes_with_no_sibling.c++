Nodes without a Sibling
Difficulty: EasyAccuracy: 18.01%Submissions: 177K+Points: 2
Given a Binary Tree, find all the nodes that don't have any siblings. You need to return a list of integers containing all the nodes that don't have a sibling in sorted order (Increasing). Two nodes are said to be siblings if they are present at the same level, and their parents are the same.

Note: The root node can not have a sibling so it cannot be included in our answer. If there are no nodes that do not have a sibling then add-1 in the list.

Examples:

Input: root[] = [37, 20, N, 113]
       37
      /   
    20
    /     
  113 

Output: [20, 113]
Explanation: Nodes 20 and 113 dont have any siblings.
Input: root[] = [1, 2, 3, 4]
       1
      / \
     2   3
    /
     4

Output: [4]
Explanation: Node 4 does not have a sibling.
Input: root[] = [37, 40, N, 13]
       37
      /   
    40
    /     
  13 

Output: [40, 13]
Explanation: Nodes 20 and 13 dont have any siblings.
Constraints:
1 ≤ number of nodes ≤ 104
1 ≤ node->data ≤ 104










void solve(Node *root,vector<int>&ans){
    if(root==NULL) return;
    
    if(root->left and !root->right){
        ans.push_back(root->left->data);
    }
    
    if(root->right and !root->left){
        ans.push_back(root->right->data);
    }
    
    solve(root->left,ans);
    solve(root->right,ans);
}
vector<int> noSibling(Node* node)
{
    // code here
    vector<int>ans;
    solve(node,ans);
    if(ans.empty()) return {-1};
    
    sort(ans.begin(),ans.end());
    return ans;
}

t.c:-O(nlogn) and s.c:-O(n) due to the vector

