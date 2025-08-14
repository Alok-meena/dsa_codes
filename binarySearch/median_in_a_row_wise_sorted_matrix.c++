

Upgrade to Premium for Doubt Support across all your problems and courses.

Explore Premium
Redirection Icon
Median in a row-wise sorted Matrix
Difficulty: HardAccuracy: 55.05%Submissions: 149K+Points: 8
Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.

Examples:

Input: mat[][] = [[1, 3, 5], 
                [2, 6, 9], 
                [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.
Input: mat[][] = [[2, 4, 9],
                [3, 6, 7],
                [4, 7, 10]]
Output: 6
Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.
Input: mat = [[3], [4], [8]]
Output: 4
Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.
Constraints:
1 ≤ n, m ≤ 400
1 ≤ mat[i][j] ≤ 2000







class Solution {
  public:
    int solve(vector<vector<int>>&mat,int tar){
        int cnt=0;
        for(int i=0;i<mat.size();i++){
            int idx=upper_bound(mat[i].begin(),mat[i].end(),tar)-mat[i].begin();
            cnt+=idx;
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        int low=INT_MAX;
        for(int i=0;i<n;i++){
            low=min(low,mat[i][0]);
        }
        
        int high=INT_MIN;
        for(int i=0;i<n;i++){
            high=max(high,mat[i][m-1]);
        }
        
        int val=(n*m)/2;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            int smaller=solve(mat,mid);
            
            if(smaller<=val){
                low=mid+1;
            }
            else high=mid-1;
        }
        
        return low;
    }
};

t.c:-O(log(maxi) * n* logm))
