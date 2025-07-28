Given a binary tree having n nodes.
Find the sum of all nodes on the longest path from root to any leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.

Example 1:

Input: 
        4        
       /  \       
      2   5      
     / \   /  \     
    7  1 2  3    
      /
     6
Output: 
13



class Solution
{
    private:
    void solve(Node *root,int len,int &maxlen,int sum,int &maxsum){
        if(root==NULL){// jb traverse krte krte root Null hua to check condition if anyof below saitfy update ans
            if(len>maxlen){//to check longest length to root to leaf
                maxlen=len;// if yes then update both
                maxsum=sum;
            }
            else if(len==maxlen){//if len is same as old one then we have to return the max sum of the both so it is also updated
                maxsum=max(sum,maxsum);
            }
            return;
        }
        
        sum=sum+root->data;// to calculate the sum also
        
        solve(root->left,len+1,maxlen,sum,maxsum);//then we are first traversing the left subtree then the right subtree
        solve(root->right,len+1,maxlen,sum,maxsum);

        //and now iske bad hame sum ko change nhi krna aor na hi length ko krna hai as these are passed as copy not value
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len=0;
        int maxlen=0;
        
        int sum=0;
        int maxsum=INT_MIN;
        
        solve(root,len,maxlen,sum,maxsum);
        
        return maxsum;
    }
};

Time Complexity: O(n)//in case of worst case for skewed tree and ow it is also n becasue we have to traverse each and every node of the tree
 Auxiliary Space: O(n)


we can also use a pair instead of this 4 variables

class Solution {
  public:
    void solve(Node *root,int len,int sum,pair<int,int>&ans){
        if(root==NULL){
            if(len>ans.first){
                ans.first=len;
                ans.second=sum;
            }
            else if(len==ans.first){
                ans.second=max(sum,ans.second);
            }
            
            return;
        }
        
        sum+=root->data;
        
        solve(root->left,len+1,sum,ans);
        solve(root->right,len+1,sum,ans);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int len=0;
        int maxlen=0;
        
        int sum=0;
        int maxsum=INT_MIN;
        
        pair<int,int>ans;//maxlen,maxsum
        
        solve(root,len,sum,ans);
        return ans.second;
    }
};








this one is preferred code ------------------------

class Solution {
  public: 
    void solve(Node *root,int len,int sum,int &maxsum,int &maxlen){
        if(root==NULL){
            return;
        }
        
        sum+=root->data;
        
        if(root->left==NULL and root->right==NULL){
            if(len>maxlen){
                maxlen=len;
                maxsum=sum;
            }
            else if(len==maxlen){
                maxsum=max(maxsum,sum);
            }
        }
        
        solve(root->left,len+1,sum,maxsum,maxlen);
        solve(root->right,len+1,sum,maxsum,maxlen);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int maxsum=0;
        int maxlen=0;
        
        solve(root,0,0,maxsum,maxlen);
        return maxsum;
    }
};
