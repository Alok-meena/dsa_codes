


UNION OF TWO SETS




#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(std::vector<int> arr1, std::vector<int> arr2) {
        // code here
        int n = arr1.size();
        int m = arr2.size();
        
        // Sort both arrays
        std::sort(arr1.begin(), arr1.end());
        std::sort(arr2.begin(), arr2.end());
        
        std::vector<int> ans;
        int i = 0, j = 0;

        // Using two pointers to merge arrays
        while (i < n || j < m) {
            if (i < n && (j >= m || arr1[i] < arr2[j])) {
                // Add arr1[i] if not already added
                if (ans.empty() || ans.back() != arr1[i]) {
                    ans.push_back(arr1[i]);
                }
                i++;
            } else if (j < m && (i >= n || arr2[j] < arr1[i])) {
                // Add arr2[j] if not already added
                if (ans.empty() || ans.back() != arr2[j]) {
                    ans.push_back(arr2[j]);
                }
                j++;
            } else {
                // Both are equal
                if (ans.empty() || ans.back() != arr1[i]) {
                    ans.push_back(arr1[i]);
                }
                i++;
                j++;
            }
        }

        return ans.size(); // Return the size of the unique elements
    }
};


2:easy one using directly the set from stl

class Solution {
  public:
    
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(vector<int> arr1, vector<int> arr2) {
        // code here
        set<int>unionset;
        for(auto i:arr1){
            unionset.insert(i);
        }
        for(auto j:arr2){
            unionset.insert(j);
        }
        return unionset.size();
    }
};

3rd way without using set

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(vector<int> arr1, vector<int> arr2) {
        // code here
        vector<int>ans;
        
        int i=0;
        int j=0;
        int n=arr1.size();
        int m=arr2.size();
        
        while(i<n && j<m){
            
            if(arr1[i]<=arr2[j]){
                if(ans.size()==0 || ans.back()!=arr1[i]){
                    ans.push_back(arr1[i]);
                }
                i++;
            }
            else{
                if(ans.size()==0 || ans.back()!=arr2[j]){
                    ans.push_back(arr2[j]);
                }
                j++;
            }
        }
        
        while(i<n){
            if(ans.size()==0 || ans.back()!=arr1[i]){
              ans.push_back(arr1[i]);
            }
            i++;
        }
        
        while(j<m){
            if(ans.size()==0 || ans.back()!=arr2[j]){
               ans.push_back(arr2[j]);
            }
            j++;
        }
        
        return ans.size();
        
    }
};

t.c:-O(n+m) and s.c:-O(n+m)
