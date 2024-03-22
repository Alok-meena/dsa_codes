Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

// to bs hm khuch nhi kr rhe har level pe jo pahla element aayega usko store kra rhe hai ab yha hmne recursion ka use kiya and we can also do it by level order
//traversal okkk

void solve(Node *root,vector<int>&v,int level){
    if(root==NULL){
        return ;
    }
    
    if(level==v.size()){
        v.push_back(root->data); // yha condition lga ki jese jese element starting vale ans me dalenge usi hisab se uski bdegi to uski size ka use kiya to check
        // whether it is first element of the level or not 
    }
    
    solve(root->left,v,level+1);// bs fir kya left right ka call level increase by 1
    solve(root->right,v,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>v;
   solve(root,v,0);
   return v;
}

Time Complexity: O(N).
Auxiliary Space: O(N).


Right view of the tree:-

            10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60

          
class Solution
{
    private:
    void solve(Node *root,vector<int>&v,int level){
    if(root==NULL){
        return ;
    }
    
    if(level==v.size()){
        v.push_back(root->data);
    }
    
        solve(root->right,v,level+1); // just one change pahle right ke liye call karna aor right to left traverse karna

    
    solve(root->left,v,level+1);
}
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>v;
   solve(root,v,0);
   return v;
    }
};


 Time Complexity: O(N).
 Auxiliary Space: O(Height of the Tree).
