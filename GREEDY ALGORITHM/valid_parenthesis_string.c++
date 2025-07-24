678. Valid Parenthesis String
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.



tried dp t.c:-O(n^2) and same s.c alright

class Solution {
public:
    bool solve(int i,int cnt,string s,vector<vector<int>>&dp){
        if(cnt<0) return false;
        if(i==s.length()){
            if(cnt==0) return true;
            return false;
        }

        if(dp[i][cnt]!=-1) return dp[i][cnt];

        if(s[i]=='('){
            return solve(i+1,cnt+1,s,dp);
        }
        else if(s[i]==')'){
            return solve(i+1,cnt-1,s,dp);
        }
        else if(s[i]=='*'){
            bool op1=solve(i+1,cnt,s,dp);
            bool op2=solve(i+1,cnt-1,s,dp);
            bool op3=solve(i+1,cnt+1,s,dp);
            return dp[i][cnt]=op1 or op2 or op3;
        }

        return dp[i][cnt]=false;
    }
    bool checkValidString(string s) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,s,dp);
    }
};



optimized t.c:O(n) and s.c:O(1)


class Solution {
public:
    bool checkValidString(string s) {
        int mini=0,maxi=0;

        for(auto i:s){
            if(i=='('){
                mini++;
                maxi++;
            }
            else if(i==')'){
                mini--;
                maxi--;
            }
            else{
                mini--;
                maxi++;
            }

            if(mini<0) mini=0;
            if(maxi<0) return false;
        }

        return mini==0;
    }
};


we used range based concept
