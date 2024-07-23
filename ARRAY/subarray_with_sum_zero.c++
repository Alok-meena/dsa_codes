Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum.
You just need to return true/false depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the driver code.

Example 1:

Input:
n = 5
arr = {4,2,-3,1,6}
Output: 
Yes
Explanation: 
2, -3, 1 is the subarray with sum 0.







1: brute force

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==0){
                    return true;
                }
            }
        }
        return false;
    }
};


2:use map

class Solution {
public:
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n) {
        unordered_set<long long> cumSumSet;
        long long cumSum = 0;

        for (int i = 0; i < n; ++i) {
            cumSum += arr[i];

            // Check if cumulative sum is zero or already exists in the set
            if (cumSum == 0 || cumSumSet.find(cumSum) != cumSumSet.end()) {
                return true;
            }

            // Add the current cumulative sum to the set
            cumSumSet.insert(cumSum);
        }

        return false;
    }
};
t.c:-O(nlogn) and s.c:-O(n)
