Given a boolean 2D array, consisting of only 1's and 0's, where each row is sorted. 
Find the 0-based index of the first row that has the maximum number of 1's.
Return the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

Examples :

Input: arr[][] = [[0, 1, 1, 1],[0, 0, 1, 1],[1, 1, 1, 1],[0, 0, 0, 0]]
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).
Input: arr[][] = [[0, 0], [1, 1]]
Output: 1
Explanation: Row 1 contains 2 1's (0-based indexing).






class Solution {
  public:
    int solve(vector<int>&v,int n){
        int count=0;
        for(int i=0;i<n;i++){
            if(v[i]==1){
                count++;
            }
        }
        return count;
    }
    int rowWithMax1s(vector<vector<int> > arr) {
        // code here
        int row=-1;
        int oneCount=0;
        for(int i=0;i<arr.size();i++){
            int count=solve(arr[i],arr[0].size());
            if(oneCount<count){
                oneCount=count;
                row=i;
            }
        }
        if(oneCount==0){
            return -1;
        }
        
        return row;
    }
};

t.c:-O(n*m) and constant space complexity


2:optimal

class Solution {
  public:
    int solve(vector<int>&v,int n){
        int value=lower_bound(v.begin(),v.end(),1)-v.begin();
        return n-value;
    }
    int rowWithMax1s(vector<vector<int> > arr) {
        // code here
        int row=-1;
        int oneCount=0;
        for(int i=0;i<arr.size();i++){
            int count=solve(arr[i],arr[0].size());
            if(count==arr[0].size()){
                return i;
            }
            if(oneCount<count){
                oneCount=count;
                row=i;
            }
        }
        return row;
    }
};

t.c:-O(n*log2(m)) as lower bound is based on binary search it will take log2(m
