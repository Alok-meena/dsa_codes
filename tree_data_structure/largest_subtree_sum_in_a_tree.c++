Largest subtree sum in a tree
Difficulty: MediumAccuracy: 54.83%Submissions: 28K+Points: 4
Given a binary tree. The task is to find subtree with maximum sum in the tree and return its sum.

Example 1:

Input:
              1
            /   \
           2      3
          / \    / \
         4   5  6   7
Output: 28
Explanation: 
As all the tree elements are positive,
the largest subtree sum is equal to
sum of all tree elements.

Example 2:
Input:
               1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
Output: 7
Explanation: 
Subtree with largest sum is : 
  -2
 /  \ 
4    5
Also, entire tree sum is also 7.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findLargestSubtreeSum() which takes the root of a binary tree and returns an integer.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 10^5
-10^3 <= tree.val <= 10^3

brute force har node pe jao aor left right k sum nikalo + root->data and store max 

class Solution {
  public:
    // Function to find largest subtree sum.
    int findsum(Node *root){
        if(root==NULL) return 0;
        
        int leftsum=findsum(root->left);
        int rightsum=findsum(root->right);
        
        int currsum=leftsum+rightsum+root->data;
        return currsum;
    }
    void solve(Node* root,int &maxi){
        if(root==NULL) return;
        
        int leftsum=findsum(root->left);
        int rightsum=findsum(root->right);
        
        int sum=leftsum+rightsum+root->data;
        maxi=max(maxi,sum);
        
        solve(root->left,maxi);
        solve(root->right,maxi);
    }
    int findLargestSubtreeSum(Node* root) {
        // Write your code here
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};


t.c:-O(n^2) and s.c:-O(h)


optimized O(n) t.c and s.c:-O(h)

class Solution {
  public:
    // Function to find largest subtree sum.
    pair<int,int> solve(Node *root){
        if(root==NULL) return {0,INT_MIN};
        
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        int currsum=left.first+right.first+root->data;
        
        pair<int,int>ans;
        ans.first=currsum;
        ans.second=max(currsum,max(left.second,right.second));
        
        return ans;
    }
    int findLargestSubtreeSum(Node* root) {
        // Write your code here
        return solve(root).second;
    }
};

alright that's it

this is optimized similar to largest sum b/w 2 leaf nodes vha hamne ek to 0 ke sath bhi comparison krvaya tha aor return me max of left right + root->data
right but yha currsum return kr rhe as we want sum of subtree not any individual path alright so this is cool 

class Solution {
  public:
    // Function to find largest subtree sum.
    int maxsumpath(Node *root,int &ans){
        if(root==NULL) return 0;

        int left=maxsumpath(root->left,ans);
        int right=maxsumpath(root->right,ans);
        int currsum=root->data+left+right;
        
        ans=max(ans,currsum);

        return currsum;
    }
    int findLargestSubtreeSum(Node* root) {
        // Write your code here
        int ans=INT_MIN;
        maxsumpath(root,ans);
        return ans;
    }
};
