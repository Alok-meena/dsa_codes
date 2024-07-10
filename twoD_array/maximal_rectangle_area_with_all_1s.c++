85. Maximal Rectangle
Solved
Hard
Topics
Companies
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1


  JUST USED THE CONCEPT OF LARGEST HISTOGRAM





class Solution {
public:
    vector<int> nextsmallerelement(vector<int>arr,int n){
        stack<int>s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);

    }
    return ans;
    }
    vector<int> prevsmallerelement(vector<int>arr,int n){
        stack<int>s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);

    }
    return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int>next(n);
        next=nextsmallerelement(heights,n);

        vector<int>prev(n);
        prev=prevsmallerelement(heights,n);

        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];

            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newarea=l*b;
            area=max(area,newarea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>histogram(matrix[0].size(),0);
        int maxi=INT_MIN;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    histogram[j]++;
                }
                else{
                    histogram[j]=0;
                }
            }
            maxi=max(maxi,largestRectangleArea(histogram));
        }
        return maxi;
    }
};

T.C:-o(n*(n+m))
