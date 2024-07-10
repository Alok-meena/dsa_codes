1143. Longest Common Subsequence
Solved
Medium
Topics
Companies
Hint
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.





1:recursion

class Solution {
public:
    int solve(string s1,string s2,int i,int j){
        if(i==s1.length() || j==s2.length()){
            return 0;
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans+=1+solve(s1,s2,i+1,j+1);
        }
        else{
            int ans1=solve(s1,s2,i+1,j);
            int ans2=solve(s1,s2,i,j+1);
            ans+=max(ans1,ans2);
        }
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1,text2,0,0);
    }
};

2:memorization

class Solution {
public:
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i==s1.length() || j==s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans+=1+solve(s1,s2,i+1,j+1,dp);
        }
        else{
            ans=max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        return solve(text1,text2,0,0,dp);
    }
};

3:bottom-up

  class Solution {
public:
   
    int solve(string &s1,string &s2){
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));

        for(int i=s1.length()-1;i>=0;i--){
            for(int j=s2.length()-1;j>=0;j--){
                int ans=0;
                if(s1[i]==s2[j]){
                    dp[i][j]+=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1,text2);
    }
};

4:space optimization

class Solution {
public:
   
    int solve(string &s1,string &s2){
       vector<int>curr(s2.length()+1,0);//dp[i]
       vector<int>next(s2.length()+1,0);//dp[i+1]

        for(int i=s1.length()-1;i>=0;i--){
            for(int j=s2.length()-1;j>=0;j--){
                int ans=0;
                if(s1[i]==s2[j]){
                    ans+=1+next[j+1];
                }
                else{
                    ans=max(next[j],curr[j+1]);
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1,text2);
    }
};

t.c:-(n*m) and s.c:-O(n/m) jo choti string hai uski length le lena
