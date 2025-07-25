132. Palindrome Partitioning II
Attempted
Hard
Topics
premium lock icon
Companies
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase English letters only.








class Solution {
public:
    bool ispalindrome(int l,int h,string s){
        while(l<h){
            if(s[l]!=s[h]) return false;
            l++;h--;
        }
        return true;
    }

    int solve(int i,string s,vector<int>&dp){
        if(i==s.length()) return 0;

        if(dp[i]!=-1) return dp[i];

        int mincost=INT_MAX;


        for(int j=i;j<s.length();j++){
            if(ispalindrome(i,j,s)){
                int cost=1+solve(j+1,s,dp);
                mincost=min(mincost,cost);
            }
        }

        return dp[i]=mincost;
    }
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(s.length()+1,-1);
        return solve(0,s,dp)-1;
    }
};

O(n^3)



bottom up

int minCut(string s) {
        int n=s.length();
        vector<int>dp(s.length()+1,0);

        for(int i=s.length()-1;i>=0;i--){
            int mincost=INT_MAX;

            for(int j=i;j<s.length();j++){
                if(ispalindrome(i,j,s)){
                    int cost=1+dp[j+1];
                    mincost=min(mincost,cost);
                }
            }

            dp[i]=mincost;
        }
        return dp[0]-1;
    }
