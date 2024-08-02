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

Time Complexity: O(2n+m) in the worst case, where n and m are the lengths of the two strings.
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

or can do like this also where we used 2d vector


class Solution {
public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>>& dp) {
        // Base case: if any string index goes out of bounds
        if (i >= s1.length() || j >= s2.length()) {
            return 0;
        }
        
        // Check if result is already computed
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // If characters match, extend the common substring
        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1, dp);
        } else {
            dp[i][j] = 0; // No common substring ending here
        }

        return dp[i][j];
    }

    int longestCommonSubstr(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxLength = 0;

        // Compute the longest common substring ending at each pair of indices
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxLength = max(maxLength, solve(s1, s2, i, j, dp));
            }
        }

        return maxLength;
    }
};



3rd:bottom-up

class Solution {
public:
    int longestCommonSubstr(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxLength = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                }
            }
        }

        return maxLength;
    }
};



Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).
