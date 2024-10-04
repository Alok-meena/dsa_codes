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
             if(sum==0){//fo rk sum==k
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
            int remove=prefixsum;//k ke liye prefixsum-k kr dena bs
            count+=mp[remove];
            mp[prefixsum]++;
        }

        return count;
        
    }
};

O(n*logn) and s.c:-O(n)


and to print all of them use 


vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    // Write your code here
    vector<vector<int>>ans;
    long long target=k;
    
    int n=a.size();

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            vector<int>output;
            long long sum=0;
            for(int k=i;k<=j;k++){
                sum+=a[k];
                if(sum>target) break;
                output.push_back(a[k]);
            }
            if(sum==target){
                 ans.push_back(output);
            }
        }
    }
    return ans;
}

O(n^3) t.c


#include <vector>
using namespace std;

vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    vector<vector<int>> ans;  // To store subarrays with sum equal to k
    int n = a.size();         // Size of the input array

    // Iterate through the array to find subarrays
    for (int i = 0; i < n; i++) {
        vector<int> output;   // Temporary vector to store the current subarray
        long long sum = 0;    // Variable to store the sum of the current subarray

        // Extend the subarray starting from index i
        for (int j = i; j < n; j++) {
            sum += a[j];      // Add the current element to the sum
            output.push_back(a[j]);  // Add the current element to the current subarray

            if (sum == k) {
                ans.push_back(output);  // If sum matches the target, store the subarray
            }
            
            // If the sum exceeds the target, break out of the loop
            if (sum > k) {
                break;
            }
        }
    }

    return ans;
}
O(n^2) t.c




Two Pointers
Approach:

 

We will use a method known as ‘sliding window’. It can be thought of as a window covering a continuous part of the array (subarray) and the end part of the subarray slide to the right all the time.
Array ‘ans’ will keep all those arrays whose sum = ‘k’.
We will use two indices: ‘startIndex’ and ‘endIndex’. This algorithm works as follows: We first fix the startIndex and will increase the endIndex (which increases the size of our current subarray). We do this till our sum <= ‘k’ or we are not out of bounds. Now we check our current sum and compare it with ‘k’.
 
Now we may encounter these cases:
sum < k.
This will be when our endIndex has reached the end of the array. Now, we can stop our program and return the array ‘ans’.
sum >= k
If sum == k,
We have found a subarray with the required sum. We will now push all the elements present from index ‘startIndex’ to index ‘endIndex’ into an array and then push this array into the array ‘ans’.
 
We now shift the startIndex (increasing it by one and hence decreasing the size of our window) but subtract the current starting element before increasing.
 
We will increase the startIndex till it is < n, after which we will return our array ‘ans’.
 

Algorithm:

 

Int ‘n’ be the size of array ‘a’ and ‘k’ be the required sum.
Initialize a 2-D array ‘ans’, which will keep all those sub-arrays whose sum = ‘k’.
Initialize three more variables, ‘start’ with 0, ‘end’ with -1, and ‘currentSum’ with 0, which correspond to starting index of the subarray, the ending index of the subarray, and the sum of the current subarray, respectively.
while ‘start < n’:
while (end + 1 < n) AND (currentSum + a[end + 1] <= ‘k’):
currentSum += a[end + 1]
end += 1
if currentSum == k:
Initialize an array ‘temp’.
Iterate from the index ‘start’ to the index ‘end’.
At each iteration, insert that element into the array ‘temp’.
After the iteration is completed, push the array ‘temp’ into the array ‘ans’.
currentSum -= a[start]
start += 1
Return ‘ans’.
 

Time Complexity
O( N ), where 'N' is the size of Array ‘a’.
 

In the worst-case scenario, we are traversing each index of array ‘a’ twice.

Hence the time complexity is O( N ).

Space Complexity
O( N ), where 'N' is the size of Array ‘a’.

 

We are using a 2-D array to store subarrays.

Hence, the space complexity is O( N ).

Code
C++ (g++ 5.4)
/*
    Time Complexity: O( N^2 ) 
    Space Complexity: O( N )

    where N is the size of array 'A'.
*/
vector<vector<int>> subarraysWithSumK(vector < int > a, long long k) {

    int n = a.size();
    
    vector<vector<int>> ans;
    // This will keep all those sub-arrays whose sum = ‘k’.

    // Iterating over 'a'
    for (int i = 0; i < n; ++i) {
        long long currentSum = 0;
        
        vector<int> temp;
        for(int j = i; j < n; ++j) {
            temp.push_back(a[j]);
            currentSum += a[j];

            if(currentSum == k) {
                ans.push_back(temp);
            }
        }
    }

    return ans;
}
