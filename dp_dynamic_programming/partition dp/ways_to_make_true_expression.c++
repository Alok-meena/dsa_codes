







the below code is only if we want true but we also want false so we have to update this

// User function Template for C++
class Solution {
  public:
    int solve(int i,int j,string &s,int istrue){
        if(i>j) return 0;
        
        //means ager 1 hi ele h to if we want true then it should be T to return 1 o/w f to return 1
        if(i==j){
            if(istrue==1) return s[i]=='T';
            else return s[i]=='F';
        }
        
        int ways=0;
        
        for(int k=i+1;k<=j-1;k=k+2){
            int lefttrue=solve(i,k-1,s,1);
            int leftfalse=solve(i,k-1,s,0);
            int righttrue=solve(k+1,j,s,1);
            int rightfalse=solve(k+1,j,s,0);
            
            if(s[k]=='&'){
                ways+=(lefttrue*righttrue);
            }
            else if(s[k]=='|'){
                int op1=lefttrue*righttrue;
                int op2=lefttrue*rightfalse;
                int op3=leftfalse*righttrue;
                ways+=(op1+op2+op3);
            }
            else if(s[k]=='^'){
                int op1=lefttrue*rightfalse;
                int op2=leftfalse*righttrue;
                ways+=(op1+op2);
            }
        }
        
        return ways;
    }
    int countWays(string &s) {
        // code here
        int n=s.length();
        
        return solve(0,n-1,1,s);
    }
};




so below is the optimized code after calculating both true and false scenarios alright


// User function Template for C++
class Solution {
  public:
    int solve(int i,int j,string &s,int istrue,vector<vector<vector<int>>>&dp){
        if(i>j) return 0;
        
        //means ager 1 hi ele h to if we want true then it should be T to return 1 o/w f to return 1
        if(i==j){
            if(istrue==1) return s[i]=='T';
            else return s[i]=='F';
        }
        
        if(dp[i][j][istrue]!=-1) return dp[i][j][istrue];
        
        int ways=0;
        
        for(int k=i+1;k<=j-1;k=k+2){
            int lt=solve(i,k-1,s,1,dp);
            int lf=solve(i,k-1,s,0,dp);
            int rt=solve(k+1,j,s,1,dp);
            int rf=solve(k+1,j,s,0,dp);
            
            if(s[k]=='&'){
                if(istrue) ways+=(lt*rt);
                else ways+=(lf*rt+lt*rf+lf*rf);
            }
            else if(s[k]=='|'){
                int op1=lt*rt;
                int op2=lt*rf;
                int op3=lf*rt;
                if(istrue) ways+=(op1+op2+op3);
                else ways+=(lf*rf);
            }
            else if(s[k]=='^'){
                int op1=lt*rf;
                int op2=lf*rt;
                if(istrue) ways+=(op1+op2);
                else ways+=(lt*rt+lf*rf);
            }
        }
        
        return dp[i][j][istrue]=ways;
    }
    int countWays(string &s) {
        // code here
        int n=s.length();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return solve(0,n-1,s,1,dp);
    }
};


t.c:--O(n^3) and s.c:-O(n^2) + O(n)
