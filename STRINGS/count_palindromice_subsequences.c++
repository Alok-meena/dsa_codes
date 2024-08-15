Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) present in the string str.
Note: You have to return the answer module 109+7;
 

Example 1:

Input: 
Str = "abcd"
Output: 
4
Explanation:
palindromic subsequence are : "a" ,"b", "c" ,"d"
 

Example 2:

Input: 
Str = "aab"
Output: 
4
Explanation:
palindromic subsequence are :"a", "a", "b", "aa"



1) brute force: by generating all possible subsequences and checking if it is a palindrome or not


HERE WE ARE ALSO CALCULATING SIMILAR TYPE OF PALINDROMES ALSO example if s="aa" then a,a,aa, are palindromes

#define mod 1000000007;
class Solution{
    public:
    /*You are required to complete below method */
    bool ispalindrome(string s){
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    void solve(string output,string s,int index,long long int &count){
        if(index>=s.length()){
            if(output.length()>0 && ispalindrome(output)){
                count++;
                count%=mod;
            }
            return;
        }
    
        //exclude
        solve(output,s,index+1,count);
    
        //include
        output.push_back(s[index]);
        solve(output,s,index+1,count);
    }
    
    
    long long int  countPS(string str)
    {
       //Your code here
       long long int count=0;
       
       string output="";
       solve(output,str,0,count);
       
       
       return count%mod;
       
    }
     
};

t.c:-exponential 


2) recursive + memorization



#define mod 1000000007
class Solution{
    public:
    /*You are required to complete below method */
    long long int solve(int i,int j,string &s,vector<vector<long long int>>&dp){
        if(i>j) return 0;
        if(i==j) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long int ans;
        
        if(s[i]==s[j]){
            //ans+= mat karna as here we are also adding mod so due to this 
          //ans might be wrong so just put the value in ans okk
            ans=(solve(i+1,j,s,dp)+solve(i,j-1,s,dp)+1)%mod;
        }
        else{
           //here +mod is done as after subtracting the results can be negative so we are adding mod as after that the results cant be negative
          //When you subtract values in modular arithmetic, the result can become negative. Since modulo operations should always yield non-negative results, you need to adjust negative values to fall within the valid 
          //range [0, mod-1].
            ans=(solve(i+1,j,s,dp)+solve(i,j-1,s,dp)-solve(i+1,j-1,s,dp)+mod)%mod;
        }
        
        return dp[i][j]=ans;
    }
    
    
    long long int  countPS(string str)
    {
       //Your code here
       int n=str.length();
       vector<vector<long long int>>dp(n,vector<long long int>(n,-1));
       return solve(0,n-1,str,dp);
       
    }

O(n^2) is t.c and s.cd

coding ninja sol

#define mod 1000000007

 int solve(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(i==j) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans;
        
        if(s[i]==s[j]){
            ans=(solve(i+1,j,s,dp)+solve(i,j-1,s,dp)+1)%mod;
        }
        else{
            ans=(solve(i+1,j,s,dp)+solve(i,j-1,s,dp)-solve(i+1,j-1,s,dp))%mod;
        }
        
        return dp[i][j]=ans;
    }
int countPalindromicSubsequences(string &s){
	// Write your code here.
	 vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        return solve(0,s.length()-1,s,dp);
}
     
};


O(n^2) is t.c and s.c
