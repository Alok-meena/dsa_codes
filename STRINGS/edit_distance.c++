
Code
Testcase
Testcase
Test Result
72. Edit Distance
Solved
Medium
Topics
Companies
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')



and with normal recursive approach t.c is O(3^min(n,m)) exponential and power of 3 as there are 3 operations which will call the recursive function again and again




class Solution {
public:
    int solve(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        if(i==s1.length()){
            return s2.length()-j;//to ham j minus isliye kr rhe hai as s2.length()-j is the length of the string which is still not converted 
            // so ye hame return krke ans me add karna hai that's why we did this
        }
        if(j==s2.length()){
            return s1.length()-i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;

        if(s1[i]==s2[j]){
            return solve(s1,s2,i+1,j+1,dp);//here return statement is required because if it is not included then the ans of these calls would be computed but never 
            //it's value will be stored so in order to store it's value do it 
        }
        else{
            int insert=1+solve(s1,s2,i,j+1,dp);
            int delete_it=1+solve(s1,s2,i+1,j,dp);
            int replace_it=1+solve(s1,s2,i+1,j+1,dp);
            ans=min(insert,min(delete_it,replace_it));
        }

        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2){
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};

t.c:-O(n*m) and s.c:-O(n*m) n and m is length of word1 and word2


bottom-up approach 


class Solution {
public:

    int solve(string s1,string s2){
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int j=0;j<m;j++){
            dp[n][j]=s2.length()-j;
        }
        for(int i=0;i<n;i++){
            dp[i][m]=s1.length()-i;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=0;
                if(s1[i]==s2[j]){
                    ans=dp[i+1][j+1];
                }
                else{
                    int insert=1+dp[i][j+1];
                    int delete_it=1+dp[i+1][j];
                    int replace_it=1+dp[i+1][j+1];
                    ans=min(insert,min(delete_it,replace_it));
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];

    }
    int minDistance(string word1, string word2){
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2);
    }
};



space optimization  

class Solution {
public:

    int solve(string s1,string s2){
        int n=s1.length();
        int m=s2.length();
        vector<int>curr(m+1,0);//size of both should be m+1 because we are converting s1 to s2 and max operations requried are length of s2 string so that's all
        //size should be of s2 string
        vector<int>next(m+1,0);

        for(int j=0;j<m;j++){
            next[j]=s2.length()-j;
        }

        //this for loop is for the last row everytime but 

       // the iin the second for loop we are changing particular index of every row so we can do it int the for for loop itself and do upate inside curr row
       // as after that next=curr will take care of it
        

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                curr[s2.length()]=s1.length()-i;

                int ans=0;
                if(s1[i]==s2[j]){
                    ans=next[j+1];
                }
                else{
                    int insert=1+curr[j+1];
                    int delete_it=1+next[j];
                    int replace_it=1+next[j+1];
                    ans=min(insert,min(delete_it,replace_it));
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return curr[0];

    }
    int minDistance(string word1, string word2){
        if(word1.length()==0) return word2.length();
        if(word2.length()==0) return word1.length();
        return solve(word1,word2);
    }
};

s.c:-O(m) and s.c:-O(n*m)
