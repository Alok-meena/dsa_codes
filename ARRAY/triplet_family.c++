Given an array arr of integers. Find whether three numbers are such that the sum of two elements equals the third element.

Example:

Input: arr[] = [1, 2, 3, 4, 5]
Output: true
Explanation: The pair (1, 2) sums to 3.
Input: arr[] = [5, 3, 4]
Output: false
Explanation: No triplets satisfy the condition.
Expected Time Complexity: O(n2)
Expected Auxilary Space: O(1)





class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        int n=arr.size();
        set<int>s;
        for(auto i:arr){
            s.insert(i);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s.find(arr[i]+arr[j])!=s.end()){
                    return true;
                }
            }
        }
        return false;
    }
};

t.c:-O(n^2) and s.c:-O(1)
