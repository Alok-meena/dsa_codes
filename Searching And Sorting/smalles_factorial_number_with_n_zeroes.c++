Smallest factorial number
Difficulty: MediumAccuracy: 38.79%Submissions: 40K+Points: 4
Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Example 1:

Input:
n = 1
Output: 5
Explanation : 5! = 120 which has at
least 1 trailing 0.
Example 2:

Input:
n = 6
Output: 25
Explanation : 25! has at least
6 trailing 0.

User Task:
Complete the function findNum() which takes an integer N as input parameters, and returns the answer.

Expected Time Complexity: O(log2 N * log5 N).
Expected Auxiliary Space: O(1).










class Solution
{
    public:
       
        int trailingZeroes(int n) {
            int count=0;
               while(n/5>0){//yha n/5 >0 kiya because jo bhi bchega divide ke bad positive to hoga hi but ex: 3 ho to /5 >0 karna jruri hai
                   count+=(n/5);
                   n=n/5;
               }
               return count;
        }  
        int findNum(int n)
        {
            
           if(n==0) return 0;
           int low=0;
           int high=5*n;
           
           int ans=-1;
           
           while(low<=high){
               int mid=low+(high-low)/2;
               
               int zeroes=trailingZeroes(mid);
               if(zeroes>=n){
                   ans=mid;
                   high=mid-1;
               }
               else{
                   low=mid+1;
               }
           }
           
           return ans;
        
        }
};
