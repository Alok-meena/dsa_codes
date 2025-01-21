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

we can also use a map data structure here like this 

class Solution {
  public:
    void preorder(Node *root,map<int,int>&m,int level){
        if(root==NULL){
            return;
        }
        
        if(m.find(level)==m.end()) m[level]=root->data;
        
        preorder(root->left,m,level+1);
        preorder(root->right,m,level+1);
        
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL) return ans;
        
        map<int,int>m;
        preorder(root,m,0);
        
        for(auto i:m){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};




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


we can do this by BFS ALSO 


class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL) return ans;
        
        queue<Node*>q;
        vector<int>v;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            Node *temp=q.front();
            q.pop();
            
            if(temp==NULL){
                ans.push_back(v[0]);
                v.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                v.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        
        return ans;
    }
};

the first element of every level and for right view either update the ans everytime 
like 

if(temp==NULL){
                ans.push_back(v[v.size()-1]); push the last element instead of the first okk
                v.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }

or just traverse the right part first 
then the left part okk ( because then first element aapka right part me aa jayega okk )


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
