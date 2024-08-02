You have been given a string ‘A’ consisting of lower case English letters. Your task is to find the length of the longest palindromic subsequence in ‘A’.

A subsequence is a sequence generated from a string after deleting some or no characters of the string without changing the order of the remaining string characters. (i.e. “ace” is a subsequence of “abcde” while “aec” is not).

A string is said to be palindrome if the reverse of the string is the same as the actual string. For example, “abba” is a palindrome, but “abbc” is not a palindrome.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10 ^ 2

Where ‘T’ is the number of test cases, and ‘N’ is the length of the string.

Time limit: 1 sec.
Sample Input 1:
2
bbabcbcab
bbbab
Sample Output 1:
7
4
Explanation of Sample Input 1:
For the first test case, the longest palindromic subsequence is “babcbab”, which has a length of 7. “bbbbb” and “bbcbb” are also palindromic subsequences of the given string, but not the longest one.

For the second test case, the longest palindromic subsequence is “bbbb”, which has a length of 4.

  


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
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string s1=s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp(s.length(),vector<int>(s1.length(),-1));
        return solve(s,s1,0,0,dp);
}
