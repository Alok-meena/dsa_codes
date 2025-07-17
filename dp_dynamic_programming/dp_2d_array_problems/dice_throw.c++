Given N dice each with M faces, numbered from 1 to M, find the number of ways to get sum X. 
X is the summation of values on each face when all the dice are thrown.

 

Example 1:

Input:
M = 6, N = 3, X = 12
Output:
25
Explanation:
There are 25 total ways to get
the Sum 12 using 3 dices with
faces from 1 to 6.




THIS QUESTION IS ALSO KNOWN AS DISTINC WAYS TO ACHIEVE THE TARGET


 below is also correct but can do like this also

int mod=1000000007;

class Solution {
public:
    int solve(int dice,int faces,int target,int index,vector<vector<int>>&dp){
        if(index>=dice) return target==0?1:0;

        if(dp[index][target]!=-1) return dp[index][target];
        
        int ans=0;
        
        for(int i=1;i<=faces;i++){
            if(target>=i) ans=(ans+solve(dice,faces,target-i,index+1,dp))%mod;
        }

        return dp[index][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,0,dp);
    }
};


more simple

class Solution {
  public:
    int solve(int dice,int x,int n,int m,vector<vector<int>>&dp){
        if(dice==n){
            if(x==0) return 1;
            return 0;
        }
        
        if(x<0) return 0;
        
        if(dp[dice][x]!=-1) return dp[dice][x];
        
        int ans=0;
        for(int face=1;face<=m;face++){
            ans+=solve(dice+1,x-face,n,m,dp);
        }
        
        return dp[dice][x]=ans;
    }
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
        return solve(0,x,n,m,dp);
    }
};

bottom up
int noOfWays(int m, int n, int X) {
        // code here
        vector<vector<int>>dp(n+2,vector<int>(X+1,0));
        
        dp[n][0]=1;
        
        for(int dice=n-1;dice>=0;dice--){
            for(int x=0;x<=X;x++){
                int ans=0;
                for(int face=1;face<=m;face++){
                    if(x-face>=0) ans+=dp[dice+1][x-face];
                }
                
                dp[dice][x]=ans;
            }
        }
        return dp[0][X];


space optimized

int noOfWays(int m, int n, int X) {
        // code here
        vector<int>next(X+1,0);
        vector<int>curr(X+1,0);
        
        next[0]=1;
        
        for(int dice=n-1;dice>=0;dice--){
            for(int x=0;x<=X;x++){
                int ans=0;
                for(int face=1;face<=m;face++){
                    if(x-face>=0) ans+=next[x-face];
                }
                
                curr[x]=ans;
            }
            next=curr;
        }
        return next[X];
    }

1:recusion

class Solution {
  public:
   
    long long solve(int faces,int dices,int target){
        if(target<0){
            return 0;//koi tarika nhi because values +ve hogi
        }
        if(target==0 && dices!=0){
            return 0;//because sari values 0 hogi
        }
        if(dices==0 && target!=0){
            return 0;//means dice hi 0 hai to target nhi bna payenge
        }
        if(target==0 && dices==0){
            return 1;//iska ek tarika hai bs
        }
        
        //so these are base cases and just like 00 01 10 11
        
        //now check for each value of the faces
        long long ans=0;
        for(int i=1;i<=faces;i++){
            ans=ans+solve(faces,dices-1,target-i);//pichli dice ke liye call kr diya and update the target
        }
        return ans;
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        return solve(M,N,X);
    }
};


2:memorization



class Solution {
  public:
   
    long long solve(int faces,int dices,int target,vector<vector<long long>>&dp){
        if(target<0){
            return 0;//koi tarika nhi because values +ve hogi
        }
        if(target==0 && dices!=0){
            return 0;//because sari values 0 hogi
        }
        if(dices==0 && target!=0){
            return 0;//means dice hi 0 hai to target nhi bna payenge
        }
        if(target==0 && dices==0){
            return 1;//iska ek tarika hai bs
        }
        
        if(dp[dices][target]!=-1){
            return dp[dices][target];
        }
        
        //so these are base cases and just like 00 01 10 11
        
        //now check for each value of the faces
        long long ans=0;
        for(int i=1;i<=faces;i++){
            ans=ans+solve(faces,dices-1,target-i,dp);//pichli dice ke liye call kr diya and update the target
        }
        dp[dices][target]=ans;
        return dp[dices][target];
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));//pahle dice ke liye n and then target x+1 
        return solve(M,N,X,dp);
    }
};


3:bottom-up approach


int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+2,vector<int>(target+1,0));


    //ye niche vala for loop nhi lagana because what we want ki sari dices use ho and then target 0 ho from base case alright
        // for(int index=0;index<=n;index++){
        //     dp[index][0]=1;
        // }
        dp[n][0]=1;

    //n is done so start with n-1 alright

        for(int index=n-1;index>=0;index--){
            for(int tar=0;tar<=target;tar++){
                int ans=0;
        
                for(int i=1;i<=k;i++){
                    if(tar>=i) ans=(ans+dp[index+1][tar-i])%mod;
                }

                dp[index][tar]=ans;
            }
        }
        return dp[0][target];
d    }

class Solution {
  public:
   
 
    long long solve(int m,int n,int t){
        vector<vector<long long>>dp(n+1,vector<long long>(t+1,0));
        
        //after analyzing base cases
        dp[0][0]=1;//baki base cases ke liye 0 to hamne kr hi rkha hai
        
        //1 se start kiya dono ko because 0 vala calculate kr liya hai
        for(int dices=1;dices<=n;dices++){
            for(int target=1;target<=t;target++){
                long long ans=0;
                for(int i=1;i<=m;i++){
                    if(target-i>=0){//because target-i can be a invalid index so handle it
                      ans=ans+dp[dices-1][target-i];//pichli dice ke liye call kr diya and update the target
                    }
                }
                dp[dices][target]=ans;
            }
        }
        return dp[n][t];
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        return solve(M,N,X);
    }
};


4:space optimization

int numRollsToTarget(int n, int k, int target) {
     
        vector<int>next(target+1,0);
        vector<int>curr(target+1,0);
        next[0]=1; //yha pe tha dp[n][0]=1 alright so niche loop me hamne n-1 se start kiya to n to next row hi hogi alright


        for(int index=n-1;index>=0;index--){
            for(int tar=0;tar<=target;tar++){
                int ans=0;
        
                for(int i=1;i<=k;i++){
                    if(tar>=i) ans=(ans+next[tar-i])%mod;
                }

                curr[tar]=ans;
            }
            next=curr;
        }
        return next[target];
    }

class Solution {
  public:
   
 
    long long solve(int m,int n,int t){
        
        vector<long long>prev(t+1,0);//size t+1 because target hi to store hoga inme
        vector<long long>curr(t+1,0);
        //after analyzing base cases
        prev[0]=1;//dp[0][0 me prev row ki bat ho rhi hai
        //baki base cases ke liye 0 to hamne kr hi rkha hai
        
        //1 se start kiya dono ko because 0 vala calculate kr liya hai
        for(int dices=1;dices<=n;dices++){
            for(int target=1;target<=t;target++){
                long long ans=0;
                for(int i=1;i<=m;i++){
                    if(target-i>=0){
                      ans=ans+prev[target-i];//pichli dice ke liye call kr diya and update the target
                    }
                }
                curr[target]=ans;
            }
            prev=curr;
        }
        return prev[t];//because yha 1 se aage bde to at last ans to prev me hi hoga
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        return solve(M,N,X);
    }
};


Expected Time Complexity: O(M*N*X)
Expected Auxiliary Space: O(N*X)

