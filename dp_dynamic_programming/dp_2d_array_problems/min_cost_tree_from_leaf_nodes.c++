1130. Minimum Cost Tree From Leaf Values
Solved
Medium
Topics
Companies
Hint
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

 

Example 1:


Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.




1:recursion


class Solution {
public:
    int solve(vector<int>&arr,map<pair<int,int>,int>&maxi,int left,int right){
        //leaf node
        if(left==right){
            return 0;
        }

        int ans=INT_MAX;

        for(int i=left;i<right;i++){
            ans=min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solve(arr,maxi,left,i)+solve(arr,maxi,i+1,right));   
        }
        return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;

        //this loop is just used to save the combination of max value among the pairs
        for(int i=0;i<arr.size();i++){
            maxi[{i,i}]=arr[i];
            for(int j=i+1;j<arr.size();j++){
                maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);//and bas piche vali value se compare krva rhe hai
            }
        }
        return solve(arr,maxi,0,arr.size()-1);
    }
};


2:memorization

class Solution {
public:
    int solve(vector<int>&arr,map<pair<int,int>,int>&maxi,int left,int right,vector<vector<int>>&dp){
        //leaf node
        if(left==right){
            return 0;
        }
        
        if(dp[left][right]!=-1){
            return dp[left][right];
        }

        int ans=INT_MAX;

        for(int i=left;i<right;i++){
            ans=min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solve(arr,maxi,left,i,dp)+solve(arr,maxi,i+1,right,dp));   
        }
        return dp[left][right]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        for(int i=0;i<arr.size();i++){
            maxi[{i,i}]=arr[i];
            for(int j=i+1;j<arr.size();j++){
                maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
            }
        }
        return solve(arr,maxi,0,arr.size()-1,dp);
    }
};

t.c:-O(n^3) and s.c:-O(

can also do bottom-up similarly

class Solution {
public:
    long long solve(int i,int j,vector<int>&arr){
        if(i>=j) return 0;
        long long ans=LLONG_MAX;
        for(int k=i;k<j;k++){
            long long leftmax=*max_element(arr.begin()+i,arr.begin()+k+1);
            long long rightmax=*max_element(arr.begin()+k+1,arr.begin()+j+1);
            long long value=leftmax*rightmax;
            long long total=1LL*value+solve(i,k,arr)+solve(k+1,j,arr);
            ans=min(ans,total);
        }

        return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
         return solve(0,arr.size()-1,arr);
    }
};


use this
