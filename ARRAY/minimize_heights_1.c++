Minimize the Heights I
Difficulty: MediumAccuracy: 26.16%Submissions: 118K+Points: 4Average Time: 25m
Given a array arr[] and positive integer k denoting heights of towers, you have to modify the height of each tower either by increasing or decreasing them by k only once.

Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

Note: A slight modification of the problem can be found here. 

Examples:

Input: arr[] = [1, 5, 8, 10], k = 2
Output: 5
Explanation: The array can be modified as [3, 3, 6, 8]. The difference between the largest and the smallest is 8 - 3 = 5.
Input: arr[] = [3, 9, 12, 16, 20], k = 3
Output: 11
Explanation: The array can be modified as [6, 12, 9, 13, 17]. The difference between the largest and the smallest is 17 - 6 = 11. 
Constraints
1 ≤ k ≤ 104
1 ≤ number of towers ≤ 105
0 ≤ arr[i] ≤ 105
  


class Solution {
  public:
    int getMinDiff(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mini=arr[0];
        int maxi=arr[n-1];
        int ans=maxi-mini;
        
        for(int i=1;i<n;i++){
            maxi=max(arr[i-1]+k,arr[n-1]-k);
            mini=min(arr[i]-k,arr[0]+k);
            
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};
