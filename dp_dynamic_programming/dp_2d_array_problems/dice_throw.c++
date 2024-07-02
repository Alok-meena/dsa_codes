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

