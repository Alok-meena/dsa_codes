Two sum -Pairs with 0 Sum
Difficulty: EasyAccuracy: 31.49%Submissions: 483K+Points: 2Average Time: 20m
Given an integer array arr, return all the unique pairs [arr[i], arr[j]] such that i != j and arr[i] + arr[j] == 0.

Note: The pairs must be returned in sorted order, the solution array should also be sorted, and the answer must not contain any duplicate pairs.

Examples:

Input: arr = [-1, 0, 1, 2, -1, -4]
Output: [[-1, 1]]
Explanation: arr[0] + arr[2] = (-1)+ 1 = 0.
arr[2] + arr[4] = 1 + (-1) = 0.
The distinct pair are [-1,1].
Input: arr = [6, 1, 8, 0, 4, -9, -1, -10, -6, -5]
Output: [[-6, 6],[-1, 1]]
Explanation: The distinct pairs are [-1, 1] and [-6, 6].
Expected Time Complexity: O(n log n)
Expected Auxiliary Space: O(n).

Constraints:
3 <= arr.size <= 105
-105 <= arr[i] <= 105



t.c is O(nlogn) and s.c:-O(n/2) * O(2) == O(n) 


class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        vector<vector<int>>ans;
        while(i<j){
            if(arr[i]+arr[j]==0){
                ans.push_back({arr[i],arr[j]});
                int value=arr[j];
                while(arr[j]==value) j--;
                
                value=arr[i];
                while(arr[i]==value) i++;
            }
            else if(arr[i]+arr[j]>0){
                j--;
            }
            else{
                i++;
            }
        }
        
        return ans;
    }
};
