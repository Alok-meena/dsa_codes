You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.
Input: s1 = "ABC", s2 "ACB"
Output: 1
Explanation: The longest common substrings are "A", "B", "C" all having length 1.



1st: brute force using recursion

class Solution {
  public:
  int solve(string &s1, string &s2, int i, int j, int count) {
        if (i >= s1.length() || j >= s2.length()) {
            return count;
        }

        int count1 = count;
        if (s1[i] == s2[j]) {
            count1 = solve(s1, s2, i + 1, j + 1, count + 1);//ham yha count+1 kr rhe hai
          //na ki 1+solve as we want continuouse order
        }
        
        int count2 = solve(s1, s2, i + 1, j, 0);//ager equal nhi aaya to in dono me count ko 0 bhejo as we are looking for substring which is always continuous
        int count3 = solve(s1, s2, i, j + 1, 0);

        return max(count, max(count1, max(count2, count3)));
    }
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        return solve(s1,s2,0,0,0);//to yha hame count alag se bhejna pda hai as here
       //we are dealing with substring not with subsequence
    }
};

Time Complexity: O(2^n+m) in the worst case, where n and m are the lengths of the two strings.
Space Complexity: O(n+m) in the worst case for the recursive stack, where n and m are the lengths of the two strings.



2nd:memorization

class Solution {
  public:
  int solve(string &s1, string &s2, int i, int j, int count,vector<vector<vector<int>>>&dp) {
        if (i >= s1.length() || j >= s2.length()) {
            return count;
        }
        
        if(dp[i][j][count]!=-1){
            return dp[i][j][count];
        }

        int count1 = count;
        if (s1[i] == s2[j]) {
            count1 = solve(s1, s2, i + 1, j + 1, count + 1,dp);
        }
        
        int count2 = solve(s1, s2, i + 1, j, 0,dp);
        int count3 = solve(s1, s2, i, j + 1, 0,dp);

        return dp[i][j][count]=max(count, max(count1, max(count2, count3)));
    }
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        vector<vector<vector<int>>>dp(s1.length(),vector<vector<int>>(s2.length(),vector<int>(s1.length(),-1)));
        return solve(s1,s2,0,0,0,dp);
    }
};



Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m*min(n,m))






4). dp method bottom up approach

class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n=s1.length();
        int m=s2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }//no require for else condition as all of the blocks are already 0
            }
        }
        return ans;
    }
};

O(n*m) t.c and s.c
