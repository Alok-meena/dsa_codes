Floor in BST
Difficulty: MediumAccuracy: 51.06%Submissions: 94K+Points: 4
You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.

Examples:

Input:
n = 7               2
                     \
                      81
                    /     \
                 42       87
                   \       \
                    66      90
                   /
                 45
x = 87
Output: 87
Explanation: 87 is present in tree so floor will be 87.
Input:
n = 4                     6
                           \
                            8
                          /   \
                        7       9
x = 11
Output: 9
Input:
n = 4                     6
                           \
                            8
                          /   \
                        7       9
x = 5
Output: -1
Constraint:
1 <= Noda data <= 109
1 <= n <= 105


  





class Solution{

public:
    void solve(Node *root,int input,int &ans){
    if(root==NULL) return;
    
    if(root->data<=input){
        ans=root->data;
        solve(root->right,input,ans);
    }
    else{
        solve(root->left,input,ans);
    }
}
    int floor(Node* root, int x) {
        // Code here
        int ans=-1;
        solve(root,x,ans);
        return ans;
    }
};


Ceil in BST
Difficulty: MediumAccuracy: 62.73%Submissions: 122K+Points: 4
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.

Example 1:

Input: root = [5, 4, 6, 3, N, N, 7, 1], X = 3
      5
    /   \
   1     7
    \
     2 
      \
       3
Output: 3
Explanation: We find 3 in BST, so ceil of 3 is 3.
Example 2:

Input: root = [10, 5, 11, 4, 7, N, N, N, N, N, 8], X = 6
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8
Output: 7
Explanation: We find 7 in BST, so ceil of 6 is 7.
Your task:
You don't need to read input or print anything. Just complete the function findCeil() to implement ceil in BST which returns the ceil of X in the given BST.

Constraints:
1 <= Number of nodes <= 105
1 <= Value of nodes<= 105

  
void solve(Node *root,int input,int &ans){
    if(root==NULL) return;
    
    if(root->data>=input){
        ans=root->data;
        solve(root->left,input,ans);
    }
    else{
        solve(root->right,input,ans);
    }
}
int findCeil(Node* root, int input) {
    
    int ans=-1;
    solve(root,input,ans);
    return ans;
    
    // return root->data;

    // Your code here
}
