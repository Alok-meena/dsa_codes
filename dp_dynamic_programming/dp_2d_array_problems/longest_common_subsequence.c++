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
    int solve(string a,string b,int i,int j){
        if(i>=a.length() or j>=b.length()) return 0;

        //if equal then include o/w exclude both one by one alright

        //inc
        int inc=0;
       //ager match ho gye to dono ko aage bda do o/w ya to string1 me aage bdao ya 2 me and dono ka max le lo bas aor khuch nhi
        if(a[i]==b[j]){
            inc=1+solve(a,b,i+1,j+1);
        }

        int exc1=0+solve(a,b,i+1,j);
        int exc2=0+solve(a,b,i,j+1);
        return max(inc,max(exc1,exc2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1,text2,0,0);
    }
};

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
    int solve(string a,string b,int i,int j,vector<vector<int>>&dp){
        if(i>=a.length() or j>=b.length()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        //inc
        int inc=0;
        if(a[i]==b[j]){
            inc=1+solve(a,b,i+1,j+1,dp);
        }

        int exc1=0+solve(a,b,i+1,j,dp);
        int exc2=0+solve(a,b,i,j+1,dp);
        return dp[i][j]=max(inc,max(exc1,exc2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        return solve(text1,text2,0,0,dp);
    }
};

t.c:-O(m*n) and s.c:-O((m*n)+(m+n)) m+n due to recursive stack alright

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

 int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i=text1.length()-1;i>=0;i--){
            for(int j=text2.length()-1;j>=0;j--){
                //inc
                int inc=0;
                if(text1[i]==text2[j]){
                    inc=1+dp[i+1][j+1];
                }

                int exc1=0+dp[i+1][j];
                int exc2=0+dp[i][j+1];
                dp[i][j]=max(inc,max(exc1,exc2));
            }
        }
        return dp[0][0];
    }

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

int longestCommonSubsequence(string text1, string text2) {
        vector<int>next(text2.length()+1,0);
        vector<int>curr(text2.length()+1,0);
        for(int i=text1.length()-1;i>=0;i--){
            for(int j=text2.length()-1;j>=0;j--){
                //inc
                int inc=0;
                if(text1[i]==text2[j]){
                    inc=1+next[j+1];
                }

                int exc1=next[j];
                int exc2=curr[j+1];
                curr[j]=max(inc,max(exc1,exc2));
            }
            next=curr;
        }
        return curr[0];
    }

alright

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
