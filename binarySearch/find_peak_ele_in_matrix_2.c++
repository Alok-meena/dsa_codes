
Code
Test Result
Testcase
Testcase
1901. Find a Peak Element II
Solved
Medium
Topics
premium lock icon
Companies
Hint
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:



Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:



Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.



brute O(n*m*4)


class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<int>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up=(i>0)?mat[i-1][j]:-1;
                int left=(j>0)?mat[i][j-1]:-1;
                int right=(j<m-1)?mat[i][j+1]:-1;
                int down=(i<n-1)?mat[i+1][j]:-1;

                int val=mat[i][j];

                if(val>up and val>left and val>right and val>down){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }

        return {-1,-1};
    }
};


optimized:

return idx of max element t.c:-O(n*m)


more optimized: 

bs apply on col len and take max ele from all rows 

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int>ans;

        int n=mat.size();
        int m=mat[0].size();

        int low=0,high=m-1;

        while(low<=high){
            int mid=(low+high)/2;

            //find max element idx (row no.)
            int idx=-1;
            int maxi=-1;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>maxi){
                    maxi=mat[i][mid];
                    idx=i;
                }
            }

            int left=  mid-1>=0? mat[idx][mid-1]:-1;
            int right= mid+1<m?  mat[idx][mid+1]:-1;
            int val=mat[idx][mid];

            if(val>left and val>right){
                return {idx,mid};
            }
            else if(left<val){
                low=mid+1;
            }
            else high=mid-1;
        }

        return {-1,-1};
    }
};

t.c:-O(nlogm) and s.c:-O(1)



