
Replace every element with the least greater element on its right
Difficulty: MediumAccuracy: 61.31%Submissions: 29K+Points: 4
Given an array arr[] of N integers and replace every element with the least greater element on its right side in the array. If there are no greater elements on the right side, replace it with -1. 

Example 1:

Input:
arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28}
Output: {18, 63, 80, 25, 32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1}
Explanation: 
The least next greater element of 8 is 18.
The least next greater element of 58 is 63 and so on.

Example 2:

Input:
arr[] = {2, 6, 9, 1, 3, 2}
Output: {3, 9, -1, 2, -1, -1}
Explanation: 
The least next greater element of 2 is 3. 
The least next greater element of 6 is 9.
least next greater element for 9 does not
exist and so on.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findLeastGreater() which takes an array arr[] of size N and returns a list as an output.

Expected Time Complexity: O(N* log N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 105






//Back-end complete function Template for C++

class Solution {
  public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        stack<int>s;
        
        vector<int>v(n);
        
        for(int i=n-1;i>=0;i--){
            int j=i+1;
            
            int ans=INT_MAX;
            
            while(j<n){
                if(ans>arr[j] and arr[j]>arr[i]){
                    ans=arr[j];
                }
                j++;
            }
            
            if(ans!=INT_MAX) v[i]=ans;
            else v[i]=-1;
        }
        
        return v;
    }
};

t.c:-O(n^2) and s.c:-O(n)



we can use set alright and find out upper bound


//Back-end complete function Template for C++

class Solution {
  public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int>v(n);
        
        set<int>s;
        
        for(int i=n-1;i>=0;i--){
            int j=i+1;
            
            auto it=s.upper_bound(arr[i]);
            if(it!=s.end()) v[i]=*it;
            else v[i]=-1;
            
            s.insert(arr[i]);
        }
        
        return v;
    }
};

t.c:-O(nlogn) and s.c:-O(n) alright
