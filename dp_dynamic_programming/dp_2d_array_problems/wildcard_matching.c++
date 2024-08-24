Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 




1:recursion

class Solution {
public:
    bool solve(string &str,string &pattern,int i,int j){
        if(i<0 && j<0){
            return true;
        }
        //case when pattern finishes and i/p string still there so no match
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            //loop 0 se j tk chalaya jha tk pattern string bchi hui hai to bs ager * mila so we can convert to empty string o/w return false
            for(int k=0;k<=j;k++){
                if(pattern[k]!='*'){
                    return false;
                }
            }
            return true;//if present
        }

        //match
        if(str[i]==pattern[j] || pattern[j]=='?'){//means match or if it is ? then do this as match then ok and if ? then replace with that only
            return solve(str,pattern,i-1,j-1);
        }
        else if(pattern[j]=='*'){
            return (solve(str,pattern,i,j-1) || solve(str,pattern,i-1,j));
        }
        return false;//if doesn't match
    }
    bool isMatch(string s, string p) {
        return solve(s,p,s.length()-1,p.length()-1);
    }
};


2:memorization

class Solution {
public:
    bool solve(string &str,string &pattern,int i,int j,vector<vector<int>>&dp){
        if(i<0 && j<0){
            return true;
        }
        //case when pattern finishes and i/p string still there so no match
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            //loop 0 se j tk chalaya jha tk pattern string bchi hui hai to bs ager * mila so we can convert to empty string o/w return false
            for(int k=0;k<=j;k++){
                if(pattern[k]!='*'){
                    return false;
                }
            }
            return true;//if present
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //match
        if(str[i]==pattern[j] || pattern[j]=='?'){//means match or if it is ? then do this as match then ok and if ? then replace with that only
            return dp[i][j]=(solve(str,pattern,i-1,j-1,dp));
        }
        else if(pattern[j]=='*'){
            //return in or as if any of the case happens
            return dp[i][j]=(solve(str,pattern,i,j-1,dp) || solve(str,pattern,i-1,j,dp));
        }
        return false;//if doesn't match
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length(),vector<int>(p.length(),-1));
        return solve(s,p,s.length()-1,p.length()-1,dp);
    }
};

now for bottom up approach we have to modify above code as 1 based indexing to handle i<0 and j<0

class Solution {
public:
    bool solve(string &str,string &pattern,int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return true;
        }
        //case when pattern finishes and i/p string still there so no match
        if(i>0 && j==0){
            return false;
        }
        if(i==0 && j>0){
            //loop 0 se j tk chalaya jha tk pattern string bchi hui hai to bs ager * mila so we can convert to empty string o/w return false
            for(int k=1;k<=j;k++){
                if(pattern[k-1]!='*'){
                    return false;
                }
            }
            return true;//if present
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //match
        if(str[i-1]==pattern[j-1] || pattern[j-1]=='?'){//means match or if it is ? then do this as match then ok and if ? then replace with that only
            return dp[i][j]=(solve(str,pattern,i-1,j-1,dp));
        }
        else if(pattern[j-1]=='*'){
            //return in or as if any of the case happens
            return dp[i][j]=(solve(str,pattern,i-1,j,dp) || solve(str,pattern,i,j-1,dp));
        }
        return false;//if doesn't match
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,-1));
        return solve(s,p,s.length(),p.length(),dp);
    }
};


3:bottom-up

  class Solution {
public:
   
    bool solve(string str,string pattern){
        vector<vector<int>>dp(str.length()+1,vector<int>(pattern.length()+1,0));
        dp[0][0]=true;
        //i>0 and first column j=0 in this false but no require as alreay done to 0
        // for(int i=1;i<str.length();i++){
        //     dp[i][0]=false;
        // }


        //here we have to do as true is also there
        for(int j=1;j<=pattern.length();j++){
            bool flag=true;
             for(int k=1;k<=j;k++){
                if(pattern[k-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;//to ager * present hai to flag ka true aagya o/w false aa jayega
        }

        //start from 1 as i-1 and j-1 is also happening
        for(int i=1;i<=str.length();i++){
            for(int j=1;j<=pattern.length();j++){
             if(str[i-1]==pattern[j-1] || pattern[j-1]=='?'){//means match or if it is ? then do this as match then ok and if ? then replace with that only
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pattern[j-1]=='*'){
                    //return in or as if any of the case happens
                    dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
                }
                else{
                    dp[i][j]= false;
                }
            }
        }
        return dp[str.length()][pattern.length()];//jo pass kiya that vhi return

    }
    bool isMatch(string s, string p) {
        return solve(s,p);
    }
};

4:space optimization

class Solution {
public:
   
    bool solve(string str,string pattern){
        vector<int>prev(pattern.length()+1,0);//i-1
        vector<int>curr(pattern.length()+1,0);//i
        prev[0]=true;
        //i>0 and first column j=0 in this false but no require as alreay done to 0
        // for(int i=1;i<str.length();i++){
        //     dp[i][0]=false;
        // }


        //here we have to do as true is also there
        for(int j=1;j<=pattern.length();j++){
            bool flag=true;
             for(int k=1;k<=j;k++){
                if(pattern[k-1]!='*'){
                    flag=false;
                    break;
                }
            }
            prev[j]=flag;//to ager * present hai to flag ka true aagya o/w false aa jayega
        }

        //start from 1 as i-1 and j-1 is also happening
        for(int i=1;i<=str.length();i++){
            for(int j=1;j<=pattern.length();j++){
             if(str[i-1]==pattern[j-1] || pattern[j-1]=='?'){//means match or if it is ? then do this as match then ok and if ? then replace with that only
                    curr[j]=prev[j-1];
                }
                else if(pattern[j-1]=='*'){
                    //return in or as if any of the case happens
                    curr[j]=(prev[j] || curr[j-1]);
                }
                else{
                    curr[j]= false;
                }
            }
            prev=curr;
        }
        return prev[pattern.length()];//jo pass kiya that vhi return

    }
    bool isMatch(string s, string p) {
        return solve(s,p);
    }
};

s.c:-O(m) and t.c:-O(n*m)
