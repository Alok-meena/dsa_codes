Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.

Example 1:

Input:      
Tree = 
          1                               
        /   \                          
       2     3
K = 3
Output: 
2
Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3

brute force

class Solution {
  public:
    void solve2(Node* root,int k,int &count,int sum){
        if(root==NULL) return;
        
        sum+=root->data;
        
        if(sum==k) count++;
        
        solve2(root->left,k,count,sum);
        solve2(root->right,k,count,sum);
    }
    
    void solve(Node* root,int k,int &count,int &sum){
        if(root==NULL){
            return;
        }
        
        solve2(root,k,count,0); //khuch nhi problem ye thi ki har node se new path start krna tha ok to hmane curr node se har bar new path start kiya but
        //is vajah se t.c O(n^2) hogyi alright
        
        solve(root->left,k,count,sum);
        solve(root->right,k,count,sum);
    }
    int sumK(Node *root, int k) {
        // code here
        int count=0;
        int sum=0;
        solve(root,k,count,sum);
        return count;
    }
};

t.c:-O(n^2) and s.c:O(n) alright

class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int> path) {
        //base case
        if(root == NULL)
            return ;
        
        path.push_back(root->data);
        
        //left
        solve(root->left, k, count, path);
        //right
        solve(root->right, k, count, path);
        
        //check for K Sum

        //we are doing it in reverse way because we are popping also during backtracking so it will consider all possible paths and it is not possible
        //we we check the sum fromm the starting okk
        int size = path.size();
        int sum = 0;// khuch nhi bs revere me sum kr ke dekh liya ager equal to k aa rhe hai to and then 
        for(int i = size-1; i>=0; i--)  {
            sum += path[i];
            if(sum == k)
                count++;
        }
        
        path.pop_back();//at last jb return honge is node se to pop bhi kr dena
    }
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};


but it's t.c is O(N*height) in worst case O(n^2) alright
  s.c:-O(N) so it can cause tle due to t.c only in some cases

2nd approach using map:-

class Solution {
  public:
    void solve(Node *root,int k,map<int,int>&m,int &count,int currsum){
        if(root==NULL) return;
        
        currsum+=root->data;
        if(currsum==k) count++;
        if(m.find(currsum-k)!=m.end()){
            count+=m[currsum-k];
        }
        
        m[currsum]++;
        
        solve(root->left,k,m,count,currsum);
        solve(root->right,k,m,count,currsum);
        
        m[currsum]--;
        // currsum-=root->data; do this only when currsum is passed by reference alright
    }
    int sumK(Node *root, int k) {
        // code here
        map<int,int>m;
        int count=0;
        int currsum=0;
        solve(root,k,m,count,currsum);
        return count;
    }
};

so this is the optimied approach t.c:-O(n) and s.c:-O(n) in case of skew tree alright
