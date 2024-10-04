Zero Sum Subarrays
Difficulty: MediumAccuracy: 51.49%Submissions: 132K+Points: 4
You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.


Examples:

Input: n = 6, arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are [0], [0], [0], [0], [0,0], and [0,0].
Input: n = 10, arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4], [-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]
Expected Time Complexity: O(n*log(n))
Expected Auxilliary Space: O(n)


1) brute force

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        
        long long ans=0;
        for (int i=0; i <n; i++){
           for (int j=i; j<n; j++){
             int sum=0;
             for (int k=i; k<=j; k++){
                 sum+=arr[k];
             }
             if(sum==0){
                 ans++;
             }
           }
        }
        
        return ans;
        
    }
};

O(n^3) t.c and s.c:-O(1)


optimized using prefix sum 


class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here

  //to ham yha pe apna longest subarray with sum k jaise hi kr rhe hai 
//but bat ye hai ki apne subarray me pahle jitne bhi sum-k hai utne hi hmare k sum ke subarray honge bs yhi apply kiya hai 
        unordered_map<int,int>mp;
        mp[0]++;
        long long count=0;
        int prefixsum=0;
        for(int i=0;i<arr.size();i++){
            prefixsum+=arr[i];
            int remove=prefixsum;
            count+=mp[remove];
            mp[prefixsum]++;
        }

        return count;
        
    }
};

O(n*logn) and s.c:-O(n)
