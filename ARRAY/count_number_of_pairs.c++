Given an array arr, and an integer k, find the number of pairs of elements in the array whose sum is k.

Examples:

Input: k = 6, arr[] = [1, 5, 7, 1]
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.
Input: k = 2, arr[] = [1, 1, 1, 1]
Output: 6
Explanation: Each 1 will produce sum 2 with any 1.


class Solution {
  public:
    int getPairsCount(const vector<int>& arr, int k) {
        // code here
        int count=0;
        for(int i=0;i<arr.size();i++){
            int sum=0;
            for(int j=i+1;j<arr.size();j++){
                sum+=arr[j]+arr[i];
                if(sum==k){
                    count++;
                    sum=0;
                }
                else{
                    sum=0;
                }
            }
            
        }
        return count;
    }
};

O(n^2)

goes for tle


