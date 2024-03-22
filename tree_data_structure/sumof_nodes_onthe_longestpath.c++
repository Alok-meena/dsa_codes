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

