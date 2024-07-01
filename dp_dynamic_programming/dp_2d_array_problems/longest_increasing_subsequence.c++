




class Solution
{
    public:
    
    int solve(int n,int a[],int currindex,int previndex){
        if(currindex==n){
            return 0;
        }
        
        int include=0;
        //include case
        if(previndex==-1 || a[previndex]<a[currindex]){//2 condn ek ki pahla element hai and 2nd uske bad vala
            include=1+solve(n,a,currindex+1,currindex);//curr ko aage bda do and prev 
            //ab curr ke equal ho jayega
        }
        
        //exclude case
        int exclude=0+solve(n,a,currindex+1,previndex);//curr to aage bd gya but not prev vo vhi rhega
        
        return max(include,exclude);
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       return solve(n,a,0,-1);
    }
};

2:memorization



yha dp me previndex+1 kr diya hai because -1 pass kiya tha to invalid index ho jata so +1 se 0 to n tk chla jayega
class Solution
{
    public:
    
    int solve(int n,int a[],int currindex,int previndex,vector<vector<int>>&dp){
        if(currindex==n){
            return 0;
        }
        
        if(dp[currindex][previndex+1]!=-1){
            return dp[currindex][previndex+1];
        }
        
        
        int include=0;
        //include case
        if(previndex==-1 || a[previndex]<a[currindex]){//2 condn ek ki pahla element hai and 2nd uske bad vala
            include=1+solve(n,a,currindex+1,currindex,dp);//curr ko aage bda do and prev 
            //ab curr ke equal ho jayega
        }
        
        //exclude case
        int exclude=0+solve(n,a,currindex+1,previndex,dp);//curr to aage bd gya but not prev vo vhi rhega
        
        dp[currindex][previndex+1]=max(include,exclude);
        return dp[currindex][previndex+1];
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       //size n hi li because 0 se n-1 tk curr and -1 se n-1 tk prev ja rha hai to total n element ho gye hai
       //because 0 se leke n-1 = n elemnt and -1 se n-1 tk n+1 eleemnts
       vector<vector<int>>dp(n,vector<int>(n+1,-1));//because curr and prev are changing
       return solve(n,a,0,-1,dp);
    }
};

t.c:-O(n^2)
s.c:-O(n^2)


3:bottom-up



class Solution
{
    public:
    

    int solve(int n,int a[]){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));//to code me hamne curr+1 kiya hai jbki start
        //n-1 se kiya to size n+1 krn hogi curr ki bhi
        
        for(int currindex=n-1;currindex>=0;currindex--){
            for(int previndex=currindex-1;previndex>=-1;previndex--){
                int include=0;
                //include case
                if(previndex==-1 || a[previndex]<a[currindex]){//2 condn ek ki pahla element hai and 2nd uske bad vala
                    include=1+dp[currindex+1][currindex+1];//aor vhi dp hai to previndex me curr ko +1 krna hi hoga
                    //curr ko aage bda do and prev 
                    //ab curr ke equal ho jayega
                }
                
                //exclude case
                int exclude=0+dp[currindex+1][previndex+1];//+1 kiya prev me so that -1 na ho invalid index
                //curr to aage bd gya but not prev vo vhi rhega
                
                dp[currindex][previndex+1]=max(include,exclude);
            }
        }
        return dp[0][0];// pev -1 tk jayga to -1+1=0
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       //size n hi li because 0 se n-1 tk curr and -1 se n-1 tk prev ja rha hai to total n element ho gye hai
       //because 0 se leke n-1 = n elemnt and -1 se n-1 tk n+1 eleemnts
       vector<vector<int>>dp(n,vector<int>(n+1,-1));//because curr and prev are changing
       return solve(n,a);
    }
}; 


but all these give tle

4:space optimized


class Solution
{
    public:
    

    int solve(int n,int a[]){
        
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        
        //CURRINDEX+1 MEANS NEXT ROW AND CURINDEX MEANS CURR ROW
        
        //to 2 row se kam chal jayega
        
        for(int currindex=n-1;currindex>=0;currindex--){
            for(int previndex=currindex-1;previndex>=-1;previndex--){
                int include=0;
                //include case
                if(previndex==-1 || a[previndex]<a[currindex]){//2 condn ek ki pahla element hai and 2nd uske bad vala
                    include=1+next[currindex+1];//aor vhi dp hai to previndex me curr ko +1 krna hi hoga
                    //curr ko aage bda do and prev 
                    //ab curr ke equal ho jayega
                }
                
                //exclude case
                int exclude=0+next[previndex+1];//+1 kiya prev me so that -1 na ho invalid index
                //curr to aage bd gya but not prev vo vhi rhega
                
                curr[previndex+1]=max(include,exclude);
            }
            
            next=curr;//har iteration ke bad aage vali row piche ke equal ho jayegi
        }
        return next[0];// pev -1 tk jayga to -1+1=0
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       //size n hi li because 0 se n-1 tk curr and -1 se n-1 tk prev ja rha hai to total n element ho gye hai
       //because 0 se leke n-1 = n elemnt and -1 se n-1 tk n+1 eleemnts
       vector<vector<int>>dp(n,vector<int>(n+1,-1));//because curr and prev are changing
       return solve(n,a);
    }
}; 


t.c:-O(n^2)
s.c:-O(n) (from O(2*n+1))
