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

in bottom up we dont require 3d dp we can use 2d only and instead of count we are using a separte ans variable alright

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


can start from n-1 also

class Solution {
  public:
     
    int longestCommonSubstr(string& s1, string& s2) {
       int n=s1.length();
        int m=s2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                    ans=max(ans,dp[i][j]);
                }//no require for else condition as all of the blocks are already 0
            }
        }
        return ans;
    }
};

alright



class Solution {
  public:
    int solve(int i,int j,int &ans,string &a,string &b){
        if(i>=a.length() or j>=b.length()) return 0;
        
        int op1=0;
        if(a[i]==b[j]){
            op1=1+solve(i+1,j+1,ans,a,b);
            ans=max(ans,op1);
        }

         //the below 2 are used only to explore further if the char's are not equal alright
        
        solve(i+1,j,ans,a,b);
        solve(i,j+1,ans,a,b);
        
        return op1;
    }
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int ans=0;
        solve(0,0,ans,s1,s2);
        
        return ans;
    }
};

brute force


class Solution {
  public:
    int solve(int i,int j,int &ans,string &a,string &b,vector<vector<int>>&dp){
        if(i>=a.length() or j>=b.length()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int op1=0;
        if(a[i]==b[j]){
            op1=1+solve(i+1,j+1,ans,a,b,dp);
            ans=max(ans,op1);
        }
        
        solve(i+1,j,ans,a,b,dp);
        solve(i,j+1,ans,a,b,dp);
        
        return dp[i][j]=op1;
    }
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int ans=0;
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        solve(0,0,ans,s1,s2,dp);
        
        return ans;
    }
};

t.c:-O(N*M)
