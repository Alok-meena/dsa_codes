Min distance between two given nodes of a Binary Tree
Difficulty: HardAccuracy: 39.13%Submissions: 128K+Points: 8Average Time: 30m
Given a binary tree with n nodes and two node values, a and b, your task is to find the minimum distance between them. The given two nodes are guaranteed to be in the binary tree and all node values are unique.

Examples :

Input: Tree = [1, 2, 3]
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: We need the distance between 2 and 3. Being at node 2, we need to take two steps ahead in order to reach node 3. The path followed will be: 2 -> 1 -> 3. Hence, the result is 2. 
Input: Tree = [11, 22, 33, 44, 55, 66, 77]
        11
      /   \
     22  33
    /  \  /  \
  44 55 66 77
a = 77, b = 22
Output: 3
Explanation: We need the distance between 77 and 22. Being at node 77, we need to take three steps ahead in order to reach node 22. The path followed will be: 77 -> 33 -> 11 -> 22. Hence, the result is 3.
Input: Tree = [1, 2, 3]
        1
      /  \
     2    3
a = 1, b = 3
Output: 1
Constraints:
2 <= number of nodes <= 105




t.c:-O(n) and s.c:-O(n) alright

khuch nhi min dist ke liye pahle to vo node nikalo jo dono ka lca hai o/w root se nikaloge to min dist nhi mielga alright then just find dist of both nodes from
that lca alright and return both distance summation



class Solution {
  public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* findlca(Node* root,int a,int b){
        if(root==NULL) return root;
        
        if(root->data==a) return root;
        if(root->data==b) return root;
        
        Node *left=findlca(root->left,a,b);
        Node *right=findlca(root->right,a,b);
        
        if(left and right) return root;
            
        return left!=NULL?left:right;
    }
    int finddist(Node *root,int a,int level){
        if(root==NULL) return -1;
        
        if(root->data==a) return level;
        
        int left=finddist(root->left,a,level+1);
        if(left!=-1) return left;
        int right=finddist(root->right,a,level+1);
        
        return right;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node *lca=findlca(root,a,b);
        
        int d1=finddist(lca,a,0);
        int d2=finddist(lca,b,0);
        return d1+d2;
    }
};



optimized approach : store path to each find lca then just return dist from each node to that lca alright 

t.c:-O(n) and s.c:-O(n)

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    void solve(Node *root,int val,vector<int>&v){
        if(root==NULL) return;
        
        v.push_back(root->data);
        
        if(root->data==val) return;
        
        solve(root->left,val,v);
        solve(root->right,val,v);
        
        if(v[v.size()-1]!=val) v.pop_back();
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        vector<int>path1;
        vector<int>path2;
        
        solve(root,a,path1);
        solve(root,b,path2);
        
        int i=0;
        while(i<path1.size()){
            if(path1[i]!=path2[i]){
                break;
            }
            i++;
        }
        
        
        for(auto i:path1) cout<<i<<" ";
        cout<<endl;
        for(auto i:path2) cout<<i<<" ";
        cout<<endl;
        cout<<i<<endl;
        
        int val1=path1.size()-i;
        int val2=path2.size()-i;
        
        return val1+val2;
    }
};



and most simple is burning tree like solution okk

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* mapping(Node *root,int a,unordered_map<Node*,Node*>&nodetoparent){
        queue<Node*>q;
        q.push(root);
        
        Node *tar=NULL;
        
        while(!q.empty()){
            Node *front=q.front();
            q.pop();
            
            if(front->data==a) tar=front;
            
            if(front->left){
                nodetoparent[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                nodetoparent[front->right]=front;
                q.push(front->right);
            }
        }
        
        return tar;
    }
    
    int solve(Node *tar,unordered_map<Node*,Node*>nodetoparent,int b){
        queue<pair<Node*,int>>q;
        unordered_map<Node*,bool>vis;
        vis[tar]=true;
        q.push({tar,0});
        
        while(!q.empty()){
            Node *front=q.front().first;
            int dist=q.front().second;
            q.pop();
            
            if(front->data==b) return dist;
            
            if(front->left and !vis[front->left]){
                vis[front->left]=true;
                q.push({front->left,dist+1});
            }
            
            if(front->right and !vis[front->right]){
                vis[front->right]=true;
                q.push({front->right,dist+1});
            }
            
            if(nodetoparent[front]!=NULL and !vis[nodetoparent[front]]){
                vis[nodetoparent[front]]=true;
                q.push({nodetoparent[front],dist+1});
            }
        }
        
        return -1;
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        unordered_map<Node*,Node*>nodetoparent;
        Node *target=mapping(root,a,nodetoparent);
        
        return solve(target,nodetoparent,b);
    }
};
