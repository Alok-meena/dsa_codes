K-th element of two Arrays
Difficulty: MediumAccuracy: 37.4%Submissions: 277K+Points: 4
Given two sorted arrays arr1 and arr2 and an element k. The task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: k = 5, arr1[] = [2, 3, 6, 7, 9], arr2[] = [1, 4, 8, 10]
Output: 6
Explanation: The final combined sorted array would be - 1, 2, 3, 4, 6, 7, 8, 9, 10. The 5th element of this array is 6.
Input: k = 7, arr1[] = [100, 112, 256, 349, 770], arr2[] = [72, 86, 113, 119, 265, 445, 892]
Output: 256
Explanation: Combined sorted array is - 72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892. 7th element of this array is 256.
Expected Time Complexity: O(log(n) + log(m))
Expected Auxiliary Space: O(log (n))






class Solution {
  public:
    void mergesort(vector<int>&ans,vector<int>& arr1, vector<int>& arr2){
        int i=0;
        int j=0;
        int n=arr1.size();
        int m=arr2.size();
        
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                ans.push_back(arr1[i++]);
            }
            else{
                ans.push_back(arr2[j++]);
            }
        }
        while(i<n){
            ans.push_back(arr1[i++]);
        }
        while(j<m){
            ans.push_back(arr2[j++]);
        }
    }
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        vector<int>ans;
        mergesort(ans,arr1,arr2);
        return ans[k-1];
    }
};

t.c:-O(n+m) and s.c also
