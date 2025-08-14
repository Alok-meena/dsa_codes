
Code
Test Result
Test Result
Testcase
2643. Row With Maximum Ones
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.

In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.

Return an array containing the index of the row, and the number of ones in it.

 

Example 1:

Input: mat = [[0,1],[1,0]]
Output: [0,1]
Explanation: Both rows have the same number of 1's. So we return the index of the smaller row, 0, and the maximum count of ones (1). So, the answer is [0,1]. 
Example 2:

Input: mat = [[0,0,0],[0,1,1]]
Output: [1,2]
Explanation: The row indexed 1 has the maximum count of ones (2). So we return its index, 1, and the count. So, the answer is [1,2].
Example 3:

Input: mat = [[0,0],[1,1],[0,0]]
Output: [1,2]
Explanation: The row indexed 1 has the maximum count of ones (2). So the answer is [1,2].







class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<int>ans(2);

        int maxi=-1;
        int row=n;

        for(int i=0;i<n;i++){
            int idx=lower_bound(mat[i].begin(),mat[i].end(),1)-mat[i].begin();
            int ones=m-idx;

            if(ones>maxi){
                maxi=ones;
                ans[0]=i;
                ans[1]=ones;
            }
        }

        return ans;
    }
};
