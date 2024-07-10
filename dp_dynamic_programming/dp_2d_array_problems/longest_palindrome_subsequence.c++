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
