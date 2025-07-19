
Code
Test Result
Testcase
Testcase
115. Distinct Subsequences
Solved
Hard
Topics
premium lock icon
Companies
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.









pretty easy just count all

class Solution {
public:
    int solve(int i,int j,string a,string b,vector<vector<int>>&dp){
        if(j==b.length()) return 1;
        if(i==a.length()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int count=0;
        if(a[i]==b[j]){
            count+=solve(i+1,j+1,a,b,dp);
        }

        count+=solve(i+1,j,a,b,dp);

        return dp[i][j]=count;
    }
    int numDistinct(string a, string b) {
        int n=a.length();
        int m=b.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++) dp[i][m]=1;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                long long count=0;
                if(a[i]==b[j]){
                    count+=dp[i+1][j+1];
                }

                count+=dp[i+1][j];

                dp[i][j]=count;
            }
        }
        return dp[0][0];
    }
};
