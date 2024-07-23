You are given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
If there are no such elements return an empty array. In this case, the output will be -1.

Note: can you handle the duplicates without using any additional Data Structure?

Examples :

Input: arr1 = [1, 5, 10, 20, 40, 80] , arr2 = [6, 7, 20, 80, 100] , arr3 = [3, 4, 15, 20, 30, 70, 80, 120]
Output: [20, 80]
Explanation: 20 and 80 are the only common elements in arr, brr and crr.
Input: arr1 = [1, 2, 3, 4, 5] , arr2 = [6, 7] , arr3 = [8,9,10]
Output: [-1]
Explanation: There are no common elements in arr, brr and crr.






class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        vector<int>ans;
        set<int>s1(arr1.begin(),arr1.end());
        set<int>s3(arr2.begin(),arr2.end());
        
        set<int>s4;
        
        for(auto i:s1){
            if(s3.find(i)!=s3.end()){
                s4.insert(i);
            }
        }
        
        set<int>s2(arr3.begin(),arr3.end());
        
        for(auto k:s2){
            if(s4.find(k)!=s4.end()){
                ans.push_back(k);
            }
        }
        
        if(ans.empty()){
            ans.push_back(-1);
        }
        return ans;
    }
};

t.c:-O(n) and s.c:-O(n)
