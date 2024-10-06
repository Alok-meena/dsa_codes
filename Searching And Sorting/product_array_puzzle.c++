Product array puzzle
Difficulty: EasyAccuracy: 33.46%Submissions: 243K+Points: 2
Given an array nums[], construct a Product Array nums[] such that nums[i] is equal to the product of all the elements of nums except nums[i].

Examples:

Input: nums[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]
Explanation: For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
Input: nums[] = [12,0]
Output: [0, 12]
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)


it can also one of the solution but with modulo division is not allowed

also most important is that if array contains 0 then division would not be possible kk 


#include <bits/stdc++.h> 
#define mod 1000000007

vector < int > productPuzzle(vector < int > & arr, int n) {
    // Write your code here.
     vector<int>ans;
     
     long long sum=1;
     for(auto i:arr){
         sum=((sum%mod)*i)%mod;
     }

     for(auto i:arr){
         int value=(sum/i)%mod;
         ans.push_back(value);
     }
     return ans;
}





1) i think this

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    long long int solve(vector<long long int>& nums,int i,int n){
        long long int sum=1;
        for(int j=0;j<n;j++){
            if(j==i) continue;
            sum*=nums[j];
        }
        return sum;
    }
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        vector<long long int>ans;
        
        for(int i=0;i<nums.size();i++){
            long long int product=solve(nums,i,nums.size());
            ans.push_back(product);
        }
        return ans;
    }
};


O(n^2) t.c and O(2*n) s.c


2) O(n) t.c and O(3n) s.c

#include <bits/stdc++.h> 
#define mod 1000000007

vector < int > productPuzzle(vector < int > & arr, int n) {
    // Write your code here.
      if(n==1) return {1};//then nothing is present in the array except that one element
        vector<int>left(n),right(n);
        left[0]=1;
        right[n-1]=1;
        
        for(int i=1;i<n;i++){
            left[i]=(left[i-1]*arr[i-1])%mod;
        }
        
        for(int i=n-2;i>=0;i--){
            right[i]=(right[i+1]*arr[i+1])%mod;
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            int value=(left[i]*right[i])%mod;
            ans.push_back(value);
        }
        
        return ans;
}

bs khuch nhi isme current element ke left and right ka product nikal liya then un donon ko multiply kr diya bas aor khuch nhi


  doing the same thing but in the same array s.c:-O(n)

  class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int n=nums.size();
        vector<long long int>ans(n,1);
        
        if(n==1) return ans;
        
        long long int temp=1;
        
        for(int i=0;i<n;i++){
            ans[i]=ans[i]*temp;
            temp*=nums[i];
        }
        
        temp=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=temp;
            temp*=nums[i];
        }
        
        return ans;
    }
    
};


  this is working for coding ninja 

#include <bits/stdc++.h>
#define mod 1000000007

vector<int> productPuzzle(vector<int>& arr, int n) {
        vector<int>ans(n,1);
        
        if(n==1) return {1};
        
        long long int temp=1;
        
        for(int i=0;i<n;i++){
            ans[i]=(ans[i]*temp)%mod;
            temp=(temp*arr[i])%mod;
        }
        
        temp=1;
        for(int i=n-1;i>=0;i--){
            ans[i]=(ans[i]*temp)%mod;
            temp=(temp*arr[i])%mod;
        }
        
        return ans;
}


