Given a number x and an array of integers arr, find the smallest subarray with sum greater than the given value.
If such a subarray do not exist return 0 in that case.

Examples:

Input: x = 51, arr[] = [1, 4, 45, 6, 0, 19]
Output: 3
Explanation: Minimum length subarray is [4, 45, 6]
Input: x = 100, arr[] = [1, 10, 5, 2, 7]
Output: 0
Explanation: No subarray exist






class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int smallest_sub_array=INT_MAX;

        for(int i=0;i<arr.size();i++){
            int sum=0;
            for(int j=i;j<arr.size();j++){
                sum+=arr[j];
                if(sum>x){
                    smallest_sub_array=min(smallest_sub_array,j-i+1);
                    break;
                }
                
                else{
                    continue;
                }
            }
        }
        
        if(smallest_sub_array==INT_MAX){
            return 0;
        }
        
        return smallest_sub_array;
    }
};

t.c:-O(n^2) ans constant space complexity


2:optimal t.c:-O(n) and s.c:-O(1)


class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        int minlength=n+1;//should contain max length

        int start=0;
        int end=0;
        int currentsum=0;//we have to declare it outside of the loop 
        //as we dont want it to be again 0 as we have to take that sum with us within 
        //the whole array
        
        while(end<n){
            while(end<n && currentsum<=x){
                currentsum+=arr[end++];
            }
            
            while(currentsum>x && start<n){
                minlength=min(minlength,end-start);
                currentsum-=arr[start++];
            }
        }
        
        if(minlength>n){
            return 0;
        }
        
        return minlength;
    }
};
