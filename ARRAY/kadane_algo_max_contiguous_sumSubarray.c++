Brute Force Approach
Intuition:
Try all possible subarrays by using nested loops and pick the subarray which has the maximum sum.

Code

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        long long ans=arr[0];

       //to yha kya ho rha hai ki ham starting se leke end tk ja rhe continuosly aor har ek element ko access krne ke bad ans update kr rhe
      //to bs max ans usme store ho hi jayega
        for(int i=0;i<arr.size();i++) {
            long long temp=0;
            for(int j=i;j<arr.size();j++) {
                temp += arr[j];
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};
Complexity:
Time Complexity: O(n2), As we are running a nested loop over the length of the array.
Space Complexity: O(1), Here no extra space is used.




  Expected Approach
Intuition:
The idea of the Kadane’s algorithm is to find the maximum sum using one traversal of the array from left to right. For every element, we decide whether we need to continue the the previous subarray (by appending current element to it) or we need to begin a new subarray. Now how do we decide this? The answer is simple, If the sum of the previous subarray is negative, then we ignore the previous subarray, otherwise we extend the previous subarray by adding current item.

Implementation: 
Initialize the variables max_so_far = arr[0](stores the maximum sum of contiguous subarray found so far) and max_ending_here = 0(that stores the maximum sum contiguous subarray ending at current index)
Run a for loop from 0 to N-1 and for each index i: 
Add the arr[i] to max_ending_here.
If  max_so_far is less than max_ending_here then update max_so_far  to max_ending_here.
If max_ending_here < 0 then update max_ending_here = 0
Return max_so_far
Example:
   Let's take the example: {-2, -3, 4, -1, -2, 1, 5, -3}
   max_so_far = arr[0] = -2
   max_ending_here = 0

   for i=0,  a[0] =  -2
   max_ending_here = max_ending_here + (-2)
   Set max_ending_here = 0 because max_ending_here < 0
   and set max_so_far = -2

   for i=1,  a[1] =  -3
   max_ending_here = max_ending_here + (-3)
   Since max_ending_here = -3 and max_so_far = -2, max_so_far will remain -2
   Set max_ending_here = 0 because max_ending_here < 0

   for i=2,  a[2] =  4
   max_ending_here = max_ending_here + (4)
   max_ending_here = 4
   max_so_far is updated to 4 because max_ending_here greater 
   than max_so_far which was -2 till now

   for i=3,  a[3] =  -1
   max_ending_here = max_ending_here + (-1)
   max_ending_here = 3

   for i=4,  a[4] =  -2
   max_ending_here = max_ending_here + (-2)
   max_ending_here = 1

   for i=5,  a[5] =  1
   max_ending_here = max_ending_here + (1)
   max_ending_here = 2

   for i=6,  a[6] =  5
   max_ending_here = max_ending_here + (5)
   max_ending_here = 7
   max_so_far is updated to 7 because max_ending_here is 
   greater than max_so_far

   for i=7,  a[7] =  -3
   max_ending_here = max_ending_here + (-3)
   max_ending_here = 4

Hence max_so_far = 7


Code

//Back-end complete function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        int n = arr.size();

        long long maxh = 0, maxf = arr[0];

        // Iterating over the array.
        for (int i = 0; i < n; i++) {
            // Updating max sum till current index.
            maxh += arr[i];
            // Storing max sum so far by choosing maximum between max
            // sum so far and max till current index.
            if (maxf < maxh)
                maxf = maxh;

            // If max sum at current index is negative, we do not need to add
            // it to result so we update it to zero.
            if (maxh < 0) //ye isliye kiya because if already our sum is going on negative then it will be going to reduce only so if it is negative then do it 0
                maxh = 0;
        }
        // returning the result.
        return maxf;
    }
};
Complexity:
Time Complexity: O(n), where is the size of the array as we are looping once the whole array.
Space Complexity: O(1), Here we are not using extra space.









  NOW WHAT IF WE HAVE TO PRINT THIS to always if currentsum 0 hai soo mtlb yhi se start kiya hai and cu>maxsum ko updte kr do end me becaue
jab bhi aage rukega to index store ho jayega then can print from start to end the respective array

  class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
   int maxSubarraySum(vector<int> &arr) {
       int currentsum=0;
       int maxsum=INT_MIN;
       for(int i=0;i<n;i++){
          if(currentsum=0){
             start=i;
          }
          currentsum+=arr[i];
          if(currentsum>maxsum){
             maxsum=currentsum;
             end=i;
          }

          if(currentsum<0){
             currentsumm=0;
          }
       }
    } 
};


long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long maxi=0;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxi=max(maxi,sum);
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

kadane's algo


but if we have to print only positive val sum


