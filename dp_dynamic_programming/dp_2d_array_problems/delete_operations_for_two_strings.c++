583. Delete Operation for Two Strings
Solved
Medium
Topics
premium lock icon
Companies
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.


same to same as edit distance

class Solution {
public:
    int solve(int i,int j,string a,string b,vector<vector<int>>&dp){
        if(i==a.length()) return b.length()-j;
        if(j==b.length()) return a.length()-i;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=INT_MAX;
        if(a[i]==b[j]){
            ans=min(ans,solve(i+1,j+1,a,b,dp));
        }
        else{
            int op1=1+solve(i+1,j,a,b,dp);
            int op2=1+solve(i,j+1,a,b,dp);
            ans=min(op1,op2);
        }

        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,word1,word2,dp);
    }
};
