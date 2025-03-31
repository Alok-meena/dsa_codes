1312. Minimum Insertion Steps to Make a String Palindrome
Solved
Hard
Topics
Companies
Hint
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.




brute force

int solve(string s,int i,int j,vector<vector<int>>&dp){
        if(i>=j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j]=solve(s,i+1,j-1,dp);
        }
        else{
            return dp[i][j]=1+min(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
        }
    }

bottom up 

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Process substrings of increasing length
        for (int len = 2; len <= n; len++) {  // Length of substring
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;  // End index of substring
                
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];  // No insertion needed
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);  // Insertions required
                }
            }
        }
        return dp[0][n - 1];  // Minimum insertions needed to make the whole string a palindrome
    }
};










what we can do is to get the min char to add to make it palindrome we dont have to count the length of the palindromic subsequence alright so just remove that and 
the char remaining will be added to get the palindrome

therefore no. of insertions=n-longest palindromic subsequence alright

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
    int minInsertions(string s) {
        return s.length()-longestPalindromeSubseq(s);
    }
};

t.c:-O(n^2) and s.c:-O(n)
