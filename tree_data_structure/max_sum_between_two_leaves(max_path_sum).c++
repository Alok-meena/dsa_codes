 Maximum Path Sum Between Two Leaves
Hard
120/120
Average time to solve is 50m
Contributed by
81 upvotes
Asked in companies
Problem statement
You are given a non-empty binary tree where each node has a non-negative integer value. Return the maximum possible sum of path between any two leaves of the given tree.

The path is also inclusive of the leaf nodes and the maximum path sum may or may not go through the root of the given tree.

If there is only one leaf node in the tree, then return -1.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 5000
0 <= data <= 10^5

Where 'N' is the number of nodes in the tree.

Time limit: 1 sec
Sample Input 1:
1
5 6 2 4 3 -1 -1 9 7 -1 -1 -1 -1 -1 -1
Sample Output 1:
26
Explanation of the Sample Input 1:

The paths between the leaves are as follows :
(1). 9->4->7               (sum = 20)
(2). 9->4->6->3            (sum = 22)
(3). 9->4->6->5->2         (sum = 26)
(4). 7->4->6->3            (sum = 20)
(5). 7->4->6->5->2         (sum = 24)
(6). 3->6->5->2            (sum = 16)

Out of all the above 6 paths, path 9->4->6->5->3 is the maximum sum path with the sum 26.
Sample Input 2:
1
2 3 -1 -1 -1
Sample Output 2:
-1
Explanation of Sample Input 2:
The given tree has only one leaf node (3), thus the answer is -1.








long long int solve(TreeNode<int> *root,long long int &ans){
    if(root==NULL){
        return 0;
    }

    // return root->val;
    

    long long int left=solve(root->left,ans);
    long long int right=solve(root->right,ans);
    long long int currsum=root->val+left+right;
    
    if(root->left and root->right)
        ans=max(ans,currsum);

    return max(left,right)+root->val;


}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    long long int ans=LLONG_MIN;
    long long int a=solve(root,ans);
    return ans==LLONG_MIN?-1:ans;
    // return ans;
}

t.c:-O(n) and s.c:-O(h) wors O(n)
