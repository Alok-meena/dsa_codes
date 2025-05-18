Median of 2 Sorted Arrays of Same Size
Difficulty: HardAccuracy: 52.17%Submissions: 2K+Points: 8Average Time: 35m
Given two sorted arrays a[] and b[] of equal size, find and return the median of the combined array after merging them into a single sorted array.

Examples:

Input: a[] = [-5, 3, 6, 12, 15], b[] = [-12, -10, -6, -3, 4]
Output: 0
Explanation: The merged array is [-12, -10, -6, -5, -3, 3, 4, 6, 12, 15]. So the median of the merged array is (-3 + 3) / 2 = 0.
Input: a[] = [2, 3, 5, 7], b[] = [10, 12, 14, 16]
Output: 8.5
Explanation: The merged array is [2, 3, 5, 7, 10, 12, 14, 16]. So the median of the merged array is (7 + 10) / 2 = 8.5.
Input: a[] = [-5], b[] = [-6]
Output: -5.5
Explanation: The merged array is [-6, -5]. So the median of the merged array is (-6 + -5) / 2 = -5.5.
Constraints: 
1 ≤ a.size(), b.size() ≤ 106
-106 ≤ a[i], b[i] ≤ 106



class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        vector<int>c(a.begin(),a.end());
        for(auto i:b) c.push_back(i);
        sort(c.begin(),c.end());
        
        int n=c.size();
        if(n%2!=0) return c[n/2];
        double v1=c[n/2];
        double v2=c[(n-1)/2];
        double v3=(v1+v2)/2;
        return v3;
    }
};

t.c:-O((n+m)log(n+m)) and s.c:-O(n+m)
