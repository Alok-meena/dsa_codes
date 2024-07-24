Given an array arr of size n and an integer x. Find if there's a triplet in the array which sums up to the given integer x.

Examples

Input:n = 6, x = 13, arr[] = [1,4,45,6,10,8]
Output: 1
Explanation: The triplet {1, 4, 8} in the array sums up to 13.
Input: n = 6, x = 10, arr[] = [1,2,4,3,6,7]
Output: 1
Explanation: Triplets {1,3,6} & {1,2,7} in the array sum to 10. 
Input: n = 6, x = 24, arr[] = [40,20,10,3,6,7]
Output: 0
Explanation: There is no triplet with sum 24. 





brute force

O(n^3)


class Solution {
  public:

    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int arr[], int n, int x) {
        // Your Code Here
        sort(arr,arr+n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]+arr[j]+arr[k]==x){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

2nd:t.c:-O(n^2) and s.c:-O(1)

  class Solution {
  public:

    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int arr[], int n, int x) {
        // Your Code Here
        sort(arr,arr+n);
        
        for(int i=0;i<n;i++){
            int value=x-arr[i];
            int low=i+1;
            int high=n-1;
            while(low<high){
                int mid=(high-low)/2;
                if(arr[low]+arr[high]==value){
                    return true;
                }
                //ager value bdi hai to high ko kam kro na to get smaller value
                else if(arr[low]+arr[high]>value){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        return false;
    }
};
