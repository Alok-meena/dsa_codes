
Code
Test Result
Testcase
Testcase
2104. Sum of Subarray Ranges
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
 

Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109
 

Follow-up: Could you find a solution with O(n) time complexity?



ques me in each subarray maxi-mini ko sum me add krna hai that's it 


so brute force O(n^2) t.c and s.c:-O(1)

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int mini = nums[i];
            int maxi = nums[i];

            for (int j = i; j < n; ++j) {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                sum += (maxi - mini);
            }
        }

        return sum;
    }
};



alright


optimized t.c:-O(n) and same s.c

we already did how to find mini sum from all subarrays using nextsmaller and prevsmaller similarly find maxi from all subarrays using nextgreater and prevgreater
just have to change signs and then just to (maxi-mini) + (maxi-mini) in each subarray == sum(maxi)-sum(mini) which we'll get so do (MAXI-MINI)  this is ans 




class Solution {
public:
     vector<int> solve1(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);

        stack<int>s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() and arr[s.top()]>=arr[i]){
                s.pop();
            }

            if(!s.empty()){
                ans[i]=s.top();
            }
            else ans[i]=-1;

            s.push(i);
        }

        return ans;
    }

    vector<int> solve2(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);

        stack<int>s;

        for(int i=0;i<n;i++){
            while(!s.empty() and arr[s.top()]>arr[i]){
                s.pop();
            }

            if(!s.empty()){
                ans[i]=s.top();
            }
            else ans[i]=-1;

            s.push(i);
        }

        return ans;
    }
    long long minimum(vector<int>& arr) {
        vector<int>nextsmaller=solve1(arr);
        vector<int>prevsmaller=solve2(arr);

        long long sum=0;

        int n=arr.size();

        for(int i=0;i<arr.size();i++){
            if(nextsmaller[i]==-1) nextsmaller[i]=n;
            long long op1=nextsmaller[i]-i;
            long long op2=i-prevsmaller[i];
            long long val=(1LL*arr[i]*op1*op2);
            sum=(sum+val);
        }

        return sum;
    }

    //maximum code

     vector<int> solve3(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);

        stack<int>s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() and arr[s.top()]<=arr[i]){
                s.pop();
            }

            if(!s.empty()){
                ans[i]=s.top();
            }
            else ans[i]=-1;

            s.push(i);
        }

        return ans;
    }

    vector<int> solve4(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);

        stack<int>s;

        for(int i=0;i<n;i++){
            while(!s.empty() and arr[s.top()]<arr[i]){
                s.pop();
            }

            if(!s.empty()){
                ans[i]=s.top();
            }
            else ans[i]=-1;

            s.push(i);
        }

        return ans;
    }
    long long maximum(vector<int>& arr) {
        vector<int>nextgreater=solve3(arr);
        vector<int>prevgreater=solve4(arr);

        long long sum=0;

        int n=arr.size();

        for(int i=0;i<arr.size();i++){
            if(nextgreater[i]==-1) nextgreater[i]=n;
            long long op1=nextgreater[i]-i;
            long long op2=i-prevgreater[i];
            long long val=(1LL*arr[i]*op1*op2);
            sum=(sum+val);
        }

        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long mini=minimum(nums);
        long long maxi=maximum(nums);
        long long diff=maxi-mini;
        return diff;
    }
};
