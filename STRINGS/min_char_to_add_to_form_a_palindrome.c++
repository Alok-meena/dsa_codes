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



brute force

class Solution {
public:
    int solve(string s,int i,int j){
        if(i>=j) return 0;

        int mini1=INT_MAX,mini2=INT_MAX;
        if(s[i]==s[j]){
            mini1=solve(s,i+1,j-1);
        }
        else{
            mini2=1+min(solve(s,i+1,j),solve(s,i,j-1));
        }
        return min(mini1,mini2);
    }
    int minInsertions(string s) {
        return solve(s,0,s.length()-1);
    }
};

top down with memorization

class Solution {
public:
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
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(s,0,s.length()-1,dp);
    }
};

t.c and s.c is O(n^2)



class Solution {
public:
int solve(string a,string b){
	    int n=a.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

		for(int i=n-1;i>=0;i--){
			for(int j=n-1;j>=0;j--){
				

				if(a[i]==b[j]){
					dp[i][j]=1+dp[i+1][j+1];
				}
				else{
					dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
				}
			}
		}

        return dp[0][0];
    }

    int minInsertions(string s) {
        int n=s.length();
        string str=s;
        reverse(str.begin(),str.end());
        
        int len=solve(str,s);
        return n-len;
    }
};

t.c:-O(n^2) and s.c:-O(n^2)









