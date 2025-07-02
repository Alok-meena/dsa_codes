Brothers From Different Roots
Difficulty: EasyAccuracy: 53.04%Submissions: 64K+Points: 2
Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

Example 1:

Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8
BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18
x = 16
Output:
3
Explanation:
The pairs are: (5, 11), (6, 10) and (8, 8)
Example 2:

Input:
BST1:
  1
   \
    3
   /
  2
BST2:
    3
   / \
  2   4
 /     
1
x = 4
Output:
3
Explanation:
The pairs are: (2, 2), (3, 1) and (1, 3)
Your Task:
You don't need to read input or print anything. Your task is to complete the function countPairs(), which takes two BST's as parameter in the form of root1 and root2 and the integer x, that returns the count of all pairs from both the BSTs whose sum is equal to x.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106 1000000
1 ≤ X ≤ 2*106 








brute force

t.c:-O(n*m) and s.c:-O(n+m)

class Solution {
  public:
    void inorder(Node* root,vector<int>&in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    int countPairs(Node* root1, Node* root2, int x) {
        vector<int>a;
        vector<int>b;
        
        inorder(root1,a);
        inorder(root2,b);
        
        int ans=0;
        
        for(int i=0;i<a.size();i++){
            int val=x-a[i];
            
            if(find(b.begin(),b.end(),val)!=b.end()) ans++;
        }
        
        return ans;
    }
};




optimized binary search


t.c:-O(nlogm)+O(n+m) == O(nlogm) and s.c:-O(n+m)


class Solution {
  public:
    void inorder(Node* root,vector<int>&in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    int countPairs(Node* root1, Node* root2, int x) {
        vector<int>a;
        vector<int>b;
        
        inorder(root1,a);
        inorder(root2,b);
        
        int ans=0;
        
        for(int i=0;i<a.size();i++){
            int val=x-a[i];
            
            int l=0;
            int e=b.size()-1;
            while(l<=e){
                int mid=(l+e)/2;
                if(b[mid]==val){
                    ans++;
                    break;
                }
                else if(b[mid]>val){
                    e=mid-1;
                }
                else l=mid+1;
            }
        }
        
        return ans;
    }
};
