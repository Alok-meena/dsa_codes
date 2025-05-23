45. Jump Game II
Medium
Topics
Companies
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].





Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

1 recursion here we are trying all possible combinations and taking out the min as answer


can also use the below code of 2d dp with memo but giving tle so use 1d dp only

class Solution {
  public:
    int solve(int idx,int jumps,vector<int>&arr,vector<vector<int>>&dp){
        if(idx>=arr.size()-1) return jumps;
        
        if(dp[idx][jumps]!=-1) return dp[idx][jumps];
        
        int mini=INT_MAX;
        for(int i=1;i<=arr[idx];i++){
            mini=min(mini,solve(idx+i,jumps+1,arr,dp));
        }
        return dp[idx][jumps]=mini;
    }
    int minJumps(vector<int>& arr) {
        // code here
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        int value=solve(0,0,arr,dp);
        return value==INT_MAX?-1:value;
    }
};

from exponential N^N to O(n^2)  t.c and s.c
class Solution {
public:
    int solve(int index,int jumps,vector<int>&nums){
        if(index>=nums.size()-1){
            return jumps;
        }

        int ans=INT_MAX;

        for(int i=1;i<=nums[index];i++){//khuch bhi ho last tk jane ke liye 1 jump to krni hi hogi
            ans=min(ans,solve(index+i,jumps+1,nums));//and we are updating the jumps to jumps+1 as we are making a jump for each 
            //and we are doing jump+1 not jump++ as jump++ will change the value of jumps and we have to use it
        }

       // When you perform jump++, the value of jump is incremented by 1, and the change persists after the operation. This is known as a post-increment operation, meaning the current value is used in the expression first, and then the value is incremented.

       // On the other hand, when you pass jump + 1 as an argument or in an expression, the value of jump remains unchanged. The expression jump + 1 simply adds 1 to the current value of jump and uses that result in the function or expression, but the original jump variable is not modified.
        
        return ans;
    }
    int jump(vector<int>& nums) {
        vector<vector<int>>dp()
        return solve(0,0,nums);
    }
};

t.c:-O(N^N) and s.c:-O(N)

another recursive solution

class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i==nums.size()-1) return 0;

        if(dp[i]!=-1) return dp[i];

        int ans=INT_MAX;
        for(int j=1;j<=nums[i];j++){
            if(i+j<nums.size()){
                int v=solve(i+j,nums,dp);
                if(v!=INT_MAX) ans=min(ans,v+1);
            }
        }

        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};


2:
class Solution {
public:
    int solve(int index,int jumps,vector<int>&nums,vector<vector<int>>&dp){
        if(index>=nums.size()-1){
            return jumps;
        }
        if(dp[index][jumps]!=-1){
            return dp[index][jumps];
        }

        int ans=INT_MAX;

        for(int i=1;i<=nums[index];i++){
            ans=min(ans,solve(index+i,jumps+1,nums,dp));
        }
        
        return dp[index][jumps]=ans;
    }
    int jump(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return solve(0,0,nums,dp);
    }
}; 
memorization
t.c ans s.c --> O(N^2)


  class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int jumps=0;
 
        while(r<nums.size()-1){
            int farthest=0;
            for(int i=l;i<=r;i++){//should be from l to r not till farthest as it is 0 at starting of every iteration
                farthest=max(i+nums[i],farthest);
            }
           //to is loop se farthest ham l se calculate kr rhe hai
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
}; 

t.c:-O(n) and s.c:-O(1)

 if this code does not handel some edge cases then  use 



class Solution{
  public:
    
    int minJumps(int arr[], int n){
        // Your code here
        int l=0;
        int r=0;
        
        if(arr[0]==0 && n==1){
            return 0;
        }
        if(arr[0]==0){
            return -1;
        }
        int jumps=0;
        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+arr[i]);
                if(farthest>=n-1){
                    return jumps+1;
                }
            }
            if(farthest<=r){
                return -1;
            }
            l=r+1;
            r=farthest;
            jumps=jumps+1;
        }
        return jumps;
        
    }
};


class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        int l=0,r=0,jumps=0;
        if(arr[0]==0) return -1;
        
        
        while(r<arr.size()-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+arr[i]);
            }
            
            if(farthest<=r) return -1;
            
            l=r+1;
            r=farthest;
            jumps++;
        }
        
        return jumps;
    }
};

t.c:-O(n) and s.c:-O(1)

  class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        int l=0,r=0;
        int jumps=0;

        //we have to run this only n-1 times because if we are reaching n-1 then we have to return the jumps alright so we have to run it till n-2 not n-1 
        //o/w it may do wrong in calculating jumps alright
        while(r<n-1){
            int farthest=0;
            
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+arr[i]);
            }
            
            if(farthest<=r) return -1;
            
            l=r+1;
            r=farthest;
            jumps++;
        }
        
        return jumps;
    }
};
