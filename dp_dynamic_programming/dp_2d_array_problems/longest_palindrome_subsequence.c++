516. Longest Palindromic Subsequence
Solved
Medium
Topics
Companies
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

brute force : find all subsequences and check if it is a palindrome or not

t.c:- O(2^n)+O(2^n)*O(n) alright
bottom up approach

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
    int longestPalindromeSubseq(string s) {
        string b;
        for(int i=s.length()-1;i>=0;i--) b.push_back(s[i]);
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,0));
        for(int i=s.length()-1;i>=0;i--){
            for(int j=s.length()-1;j>=0;j--){
                //inc
                int inc=0;
                if(s[i]==b[j]){
                    inc=1+dp[i+1][j+1];
                }

                int exc1=0+dp[i+1][j];
                int exc2=0+dp[i][j+1];
                dp[i][j]=max(inc,max(exc1,exc2));
            }
        }
        return dp[0][0];
    }
};

t.c:-O(n^2)




#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
int solve(string &s1,string &s2){
       vector<int>curr(s1.length()+1,0);//dp[i]
       vector<int>next(s1.length()+1,0);//dp[i+1]

        for(int i=s1.length()-1;i>=0;i--){
            for(int j=s2.length()-1;j>=0;j--){
                int ans=0;
                if(s1[i]==s2[j]){
                    ans=1+next[j+1];
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
    int longestPalindromeSubseq(string s) {
        string reverseString=s;
        reverse(reverseString.begin(),reverseString.end());
        int ans=solve(s,reverseString);
        return ans;
    }
};
