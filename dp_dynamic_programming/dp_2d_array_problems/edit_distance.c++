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





1:recursion


class Solution {
public:
    int solve(string s1,string s2,int i,int j){
        //means length(s1)<s2 so remaining characters of s2 ko s1 me lga diya with ==operations
        if(i==s1.length()){
            return s2.length()-j;
        }
        if(j==s2.length()){
            return s1.length()-i;
        }

        int ans=0;
        if(s1[i]==s2[j]){
            return solve(s1,s2,i+1,j+1);//aage bda diya because if same characters then no operation required
        }
        else{
            //add 1 to each as some operation is done to achieve our target
            int insertAns=1+solve(s1,s2,i,j+1);//insert kr diya to ex horse and ros to insert kiya to h to vhi rhega na to i and r maatch ho gya to j+1
            int deleteAns=1+solve(s1,s2,i+1,j);
            int replaceAns=1+solve(s1,s2,i+1,j+1);
            ans=min(insertAns,min(deleteAns,replaceAns));
        }
        return ans;
    }
    int minDistance(string word1, string word2) {
        return solve(word1,word2,0,0);
    }
};

2:memorization


class Solution {
public:
    int solve(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        //means length(s1)<s2 so remaining characters of s2 ko s1 me lga diya with ==operations
        if(i==s1.length()){
            return s2.length()-j;
        }
        if(j==s2.length()){
            return s1.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;
        if(s1[i]==s2[j]){
            return solve(s1,s2,i+1,j+1,dp);//aage bda diya because if same characters then no operation required
        }
        else{
            //add 1 to each as some operation is done to achieve our target
            int insertAns=1+solve(s1,s2,i,j+1,dp);
            int deleteAns=1+solve(s1,s2,i+1,j,dp);
            int replaceAns=1+solve(s1,s2,i+1,j+1,dp);
            ans=min(insertAns,min(deleteAns,replaceAns));
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
    }
};

3:bottom-up

  class Solution {
public:
    
    int solve(string word1,string word2){
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));//n+1 and m+1 as we are accessing n and m

        for(int j=0;j<m;j++){
            dp[n][j]=word2.length()-j;
        }
        for(int i=0;i<n;i++){
            dp[i][m]=word1.length()-i;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=0;
                if(word1[i]==word2[j]){
                    //yha return kr rhe the to error na aaye so store in ans
                  
                    ans=dp[i+1][j+1];//aage bda diya because if same characters then no operation required
                }
                else{
                    //add 1 to each as some operation is done to achieve our target
                    int insertAns=1+dp[i][j+1];
                    int deleteAns=1+dp[i+1][j];
                    int replaceAns=1+dp[i+1][j+1];
                    ans=min(insertAns,min(deleteAns,replaceAns));
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];

    }
    int minDistance(string word1, string word2) {
        return solve(word1,word2);
    }
};

4:space optimization
class Solution {
public:
    
    int solve(string word1,string word2){
        int n=word1.length();
        int m=word2.length();
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);

        for(int j=0;j<=m;j++){
            next[j]=m-j;
        }
      

        for(int i=n-1;i>=0;i--){
            //catch do this using the base case
             curr[m]=n-i;//means har row me last index of column me ye ans hoga
            //to ham next me curr dal rhe to ye ans curr me hi store karna hoga aapko
            for(int j=m-1;j>=0;j--){

              

                int ans=0;
                if(word1[i]==word2[j]){
                    ans=next[j+1];//aage bda diya because if same characters then no operation required
                }
                else{
                    //add 1 to each as some operation is done to achieve our target
                    int insertAns=1+curr[j+1];
                    int deleteAns=1+next[j];
                    int replaceAns=1+next[j+1];
                    ans=min(insertAns,min(deleteAns,replaceAns));
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];

    }
    int minDistance(string word1, string word2) {
        //if word1 is empty the we have to insert all elements of word2 into a and
        //if b is empty then length of word1;
        
        //now need to include as we have the base case 2 just after first loop which will handle it
       // // if(word1.length()==0){
       //      return word2.length();
       //  }
       //  if(word2.length()==0){
       //      return word1.length();
       //  }
        return solve(word1,word2);
    }
};
