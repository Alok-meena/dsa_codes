
Code
Test Result
Testcase
Testcase
1092. Shortest Common Supersequence 
Solved
Hard
Topics
premium lock icon
Companies
Hint
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.



length of this supersequence will be n+m-len(lcs) alright

dry run will clear u more


just do bottom up dry run of lcs used to print lcs

class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n=a.length();
        int m=b.length();
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ans=0;
                if(a[i-1]==b[j-1]){
                    ans=1+dp[i-1][j-1];
                }
                else{
                    int op1=dp[i-1][j];
                    int op2=dp[i][j-1];
                    ans+=max(op1,op2);
                }

                dp[i][j]=ans;
            }
        }

            


        string ans="";  // initialize with dummy chars
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                ans+=a[i-1];
                i--;
                j--;
            } else if (dp[i][j - 1] > dp[i - 1][j]) {
                ans+=b[j-1];
                j--;
            } else {
                ans+=a[i-1];
                i--;
            }
        }

        while(i>0){
            ans+=a[i-1];i--;
        }
        while(j>0){
            ans+=b[j-1];j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;


    }
};
