First negative in every window of size k
Difficulty: MediumAccuracy: 48.61%Submissions: 172K+Points: 4
Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.

Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window {-8, 2}: First negative integer is -8.
Window {2, 3}: No negative integers, output is 0.
Window {3, -6}: First negative integer is -6.
Window {-6, 10}: First negative integer is -6.
Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
Output: [-1, -1, -7, -15, -15, 0] 
Explanation:
Window {12, -1, -7}: First negative integer is -1.
Window {-1, -7, 8}: First negative integer is -1.
Window {-7, 8, -15}: First negative integer is -7.
Window {8, -15, 30}: First negative integer is -15.
Window {-15, 30, 16}: First negative integer is -15.
Window {30, 16, 28}: No negative integers, output is 0.
Input: arr[] = [12, 1, 3, 5] , k = 3
Output: [0, 0] 
Explanation:
Window {12, 1, 3}: No negative integers, output is 0.
Window {1, 3, 5}: No negative integers, output is 0.

Constraints:
1 <= arr.size() <= 106
-105 <= arr[i] <= 105
1 <= k <= arr.size()







class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        int n=arr.size();
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n and i+k<=n;i++){
            bool found=false;
            for(int j=i;j<k+i;j++){
                if(arr[j]<0){
                    q.push(arr[j]);
                    found=true;
                    break;
                }
            }
            if(!found){
                q.push(0);
            }
        }
        
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

s.c:-O(n) and t.c:-O(n*k)


optimized is using deque ( because during moving to the next window front element is popping and back is pushing so only possible in deque okk)


#include <bits/stdc++.h>

class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        int n=arr.size();
        
        deque<int>dq;
        vector<int>ans;
        
        for(int i=0;i<k;i++){
            if(arr[i]<0){
                dq.push_back(i);
            }
        }
        
        if(dq.size()>0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        for(int i=k;i<n;i++){ //ab ye i vale ko window ka last index mano okk jo add ho rha hai to n tk hi chlana pdega right as first k size window is processed
          //already
            if(!dq.empty() and i-dq.front()>=k){
                dq.pop_front();
            }
            
            if(arr[i]<0){
                dq.push_back(i);
            }
            
            if(dq.size()>0){
                ans.push_back(arr[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};

t.c:-O(n) and s.c:-O(n)
