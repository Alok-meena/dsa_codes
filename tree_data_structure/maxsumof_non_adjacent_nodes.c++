Given a binary tree with a value associated with each node,
we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a 
constraint that no two chosen node in subset should be directly connected that is,
if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.





class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node *root){
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
        
        pair<int,int>ans;
        //to hamne pahle me rkha hai curr level ko include krke and second me hai usae exclude krke to vhi add hoga okk
        ans.first=root->data+left.second+right.second;// yha pe root ko include kiya to baki jo return aaya hai uske first ko ignore / exclude and 
            //aor second ko utha lo

        //and then curr ko exclude krke niche vali level yani first or usse niche level tk k sum yani second le skte hai but we have to maximize our answer
        //so we have to take max of both  and add them okk
        ans.second=max(left.first,left.second)+max(right.first,right.second);// then second me hm current ko ignore krenge to bche hue sb me se max le lenge
        return ans;
    }
    
    int getMaxSum(Node *root) 
    {
        pair<int,int>ans=solve(root);//to hmne ans me int,int bnaya jisme pahla vala store krega by including current and excluding curr level to uper dekho
        return max(ans.first,ans.second);
    }
};


Expected Time Complexity: O(Number of nodes in the tree).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes in the tree ≤ 10000
1 ≤ Value of each node ≤ 100000
