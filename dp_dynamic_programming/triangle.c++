120. Triangle
Attempted
Medium
Topics
premium lock icon
Companies
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?




if in this ques we can go to any value then code is 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sum=0;
        int n=triangle.size();
        for(int i=0;i<n;i++){
            sort(triangle[i].begin(),triangle[i].end());
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<triangle[i].size();j++) cout<<triangle[i][j]<<" ";
            cout<<endl;
        }

        for(int i=0;i<triangle.size();i++){
            sum+=triangle[i][0];
        }

        return sum;
    }
};

but we cant use this code here



class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&v,vector<vector<int>>&dp){
        if(i==v.size()-1) return v[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int op1=v[i][j]+solve(i+1,j,v,dp);

        int op2=v[i][j]+solve(i+1,j+1,v,dp);

        return dp[i][j]=min(op1,op2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size()+1,vector<int>(triangle.size()+1,-1));
        return solve(0,0,triangle,dp);
    }
}; can be solved like this because we can only move to i+1 j or i+1 j+1 alright



bottom up

int minimumTotal(vector<vector<int>>& v) {
        vector<vector<int>>dp(v.size()+2,vector<int>(v.size()+2,0));

        for(int i=v.size()-1;i>=0;i--){
            for(int j=i;j>=0;j--){  //very imp thing ki j ko start karna i se because each ith row has i+1 eleemnts alright nhi to wrnog ho jayega
                int op1=v[i][j]+dp[i+1][j];

                int op2=v[i][j]+dp[i+1][j+1];

                dp[i][j]=min(op1,op2);
            }
        }
        return dp[0][0];
    }

