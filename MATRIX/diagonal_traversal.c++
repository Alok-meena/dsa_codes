
Code
Test Result
Testcase
Testcase
498. Diagonal Traverse
Solved
Medium
Topics
premium lock icon
Companies
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105







class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;

        int dir=1; //1 -> up right and 0 - >left down

        int i=0,j=0;
        int n=mat.size();
        int m=mat[0].size();

        int total=n*m;
        int cnt=0;

        while(cnt<total){
            if(i>=0 and i<n and j>=0 and j<m) ans.push_back(mat[i][j]);

            if(dir==1){
                i--;
                j++;

                if(i<0 and j>=m){
                    j--;
                    i=i+2;
                    dir=0;
                }
                else if(i<0){
                    i=0;
                    dir=0;
                }
                else if(j>=m){
                    j--;
                    i=i+2;
                    dir=0;
                }
            }
            else if(dir==0){
                i++;
                j--;

                if(j<0 and i>=n){
                    j=j+2;
                    i--;
                    dir=1;
                }
                else if(j<0){
                    j=0;
                    dir=1;
                }
                else if(i>=n){
                    i=n-1;
                    j=j+2;
                    dir=1;
                }
            }

            cnt++;
        }

        return ans;
    }
};
