Given an array a of integers of length n, find the nearest smaller number for every element such that the smaller element is on left side.If no small element present on the left print -1.

Example 1:

Input: n = 3
a = {1, 6, 2}
Output: -1 1 1
Explaination: There is no number at the 
left of 1. Smaller number than 6 and 2 is 1.
Example 2:

Input: n = 6
a = {1, 5, 0, 3, 4, 5}
Output: -1 1 -1 0 3 4
Explaination: Upto 3 it is easy to see 
the smaller numbers. But for 4 the smaller 
numbers are 1, 0 and 3. But among them 3 
is closest. Similary for 5 it is 4.
Your Task:
You do not need to read input or print anything. Your task is to complete the function leftSmaller() which takes n and a as input parameters and returns the list of smaller numbers.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 10000
0 ≤ a[i] ≤ 104








class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        stack<int>s;
    vector<int>ans(n);
    s.push(-1);

    for(int i=0;i<n;i++){
        while(s.top()>=a[i]){
            s.pop();
        }

        if(!s.empty()){
            ans[i]=s.top();
        }
        s.push(a[i]);
    }
    return ans;
    }
};


also include empty condition

class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n);

        stack<int>s;
    
        for(int i=0;i<n;i++){
            while(!s.empty() and s.top()>=arr[i]){
                s.pop();
            }
    
            if(s.empty()){
                ans[i]=-1;
            }
            else ans[i]=s.top();
    
            s.push(arr[i]);
        }
    
        return ans;
    }
};
