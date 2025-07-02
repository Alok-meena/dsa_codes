BST with Dead End
Difficulty: MediumAccuracy: 35.99%Submissions: 96K+Points: 4
You are given a Binary Search Tree (BST) containing unique positive integers greater than 0.

Your task is to determine whether the BST contains a dead end.

Note: A dead end is a leaf node in the BST such that no new node can be inserted in the BST at or below this node while maintaining the BST property and the constraint that all node values must be > 0.

Examples:

Input: root[] = [8, 5, 9, 2, 7, N, N, 1]

Output: true
Explanation: Node 1 is a Dead End in the given BST.
Input: root[] = [8, 7, 10, 2, N, 9, 13]

Output: true
Explanation: Node 9 is a Dead End in the given BST.
Constraints:
1 ≤ number of nodes ≤ 3000
1 ≤ node->data ≤ 105


t.c:-O(N) and s.c:-O(h)



class Solution {
  public:
    bool solve(Node* root,int mini,int maxi){
        if(root==NULL) return false;
        
        if(mini==maxi) return true;
        
        return solve(root->left,mini,root->data-1) or solve(root->right,root->data+1,maxi);
    }
    bool isDeadEnd(Node *root) {
        // Code here
        return solve(root,1,INT_MAX);
    }
};
