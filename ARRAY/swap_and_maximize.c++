Swap and Maximize
Difficulty: EasyAccuracy: 64.35%Submissions: 35K+Points: 2
Given an array arr[ ] of positive elements. Consider the array as a circular array, meaning the element after the last element is the first element of the array. The task is to find the maximum sum of the absolute differences between consecutive elements with shuffling of array elements allowed i.e. shuffle the array elements and make [a1..an] such order that  |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1| is maximized.

Examples:

Input: arr[] = [4, 2, 1, 8]
Output: 18
Explanation: After Shuffling, we get [1, 8, 2, 4]. Sum of absolute difference between consecutive elements after rearrangement = |1 - 8| + |8 - 2| + |2 - 4| + |4 - 1| = 7 + 6 + 2 + 3 = 18.
Input: arr[] = [10, 12]
Output: 4
Explanation: No need of rearrangement. Sum of absolute difference between consecutive elements = |10 - 12| + |12 - 10| = 2 + 2 = 4.







class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        long long sum=0;
        vector<int>v;
        sort(arr.begin(),arr.end());
        int i=0;
        int j=arr.size()-1;
        
        while(i<=j){
            v.push_back(arr[i]);
            v.push_back(arr[j]);
            i++;j--;
        }
        
     
        
        
        for(int i=0;i<v.size()-1;i++){
            sum+=abs(v[i]-v[i+1]);
        }
        
        sum+=abs(v[v.size()-1]-v[0]);
        return sum;
    }
};
