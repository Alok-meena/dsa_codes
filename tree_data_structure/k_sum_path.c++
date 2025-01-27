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


but it's t.c is O(N*height)
  s.c:-O(N) so it can cause tle due to t.c only in some cases

2nd approach using map:-

class Solution{
    private:
     #define ll long long
    map<ll ,int> mp;
    int ans=0;
    void solve(Node* root, int targetSum,ll currSum){
        if(root==NULL) return;
        currSum+=root->data;
        ans+=mp[currSum-targetSum];//it mean between the ongoing process there is a place where targetSum is generated.
        mp[currSum]++;
        solve(root->left , targetSum,currSum);
        solve(root->right , targetSum,currSum);
        mp[currSum]--;
        currSum-=root->data;

    }
  public:
    int sumK(Node *root,int k)
    {
        // code here 
        mp[0]++;
        ll currSum=0;
        solve(root,k,currSum);
        return ans;
    }
};
