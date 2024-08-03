You have been given two Strings “STR1” and “STR2” of characters. Your task is to find the length of the longest common subsequence.

A String ‘a’ is a subsequence of a String ‘b’ if ‘a’ can be obtained from ‘b’ by deletion of several (possibly, zero or all) characters. A common subsequence of two Strings is a subsequence that is common to both Strings.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 50 
1 <= |STR1| <= 10^2
1 <= |STR2| <= 10^2

Where |STR1| and |STR2| denote the length of “STR1” and “STR2” respectively. 

Time Limit: 1 sec 
Sample Input 1 :
2
abc cadb
pqr tpuqvr
Sample output 1 :
2
3
Explanation For Sample Input 1 :
For the first test case, the longest common subsequence is “ab” and its length is 2.

For the second test case, the longest common subsequence is “pqr” and its length is 3.    




#include <bits/stdc++.h>
int solve(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        if(i>=s1.length()){
            return 0;
        }
        if(j>=s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans;
        if(s1[i]==s2[j]){
            ans=1+solve(s1,s2,i+1,j+1,dp);
        }
        else{
            ans=max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
        }

        return dp[i][j]=ans;
    }
int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  vector<vector<int>>dp(str1.length(),vector<int>(str2.length(),-1));
  return solve(str1,str2,0,0,dp);
}


top down

TO IS CODE ME HAM TOP DOWN JA RHE HAI THAT'S WHY i+1 and j+1 se compare kiya hai aor bottom up me i-1 and j-1 se

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


bottom up



#include <vector>

yes we can compare it with the prev

int solve(string &s1,string &s2){
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));

        for(int i=1;i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                int ans=0;
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]+=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
int lcs(string s, string t)
{
	//Write your code here
	return solve(s,t);
}
