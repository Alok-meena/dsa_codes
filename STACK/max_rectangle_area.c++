Max rectangle
Difficulty: HardAccuracy: 36.43%Submissions: 111K+Points: 8
Given a binary matrix mat[][] of size n * m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Examples:

Input: mat[][] = [[0, 1, 1, 0],
                [1, 1, 1, 1],
                [1, 1, 1, 1],
                [1, 1, 0, 0]]
Output: 8
Explanation: The largest rectangle with only 1’s is from (1, 0) to (2, 3) which is
[1, 1, 1, 1]
[1, 1, 1, 1]
and area is 4 *2 = 8.
Input: mat[][] = [[0, 1, 1],
                [1, 1, 1],
                [0, 1, 1]]
Output: 6
Explanation: The largest rectangle with only 1’s is from (0, 1) to (2, 2) which is
[1, 1]
[1, 1]
[1, 1]
Constraints:
1<= mat.size(), mat[0].size()<=1000
0<=mat[][]<=1








class Solution {
  public:
    // Function to calculate the maximum area of a rectangle
    // in the given matrix.
    void solve2(vector<int>&prevsmaller,vector<int>&heights,int n){
        stack<int>s;

        for(int i=0;i<n;i++){
            while(!s.empty() and heights[s.top()]>=heights[i]){
                s.pop();
            }

            if(s.empty()){
                prevsmaller[i]=-1;
            }
            else prevsmaller[i]=s.top();

            s.push(i);
        }
    }
    void solve1(vector<int>&nextsmaller,vector<int>&heights,int n){
        stack<int>s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() and heights[s.top()]>=heights[i]){
                s.pop();
            }

            if(s.empty()){
                nextsmaller[i]=-1;
            }
            else nextsmaller[i]=s.top();

            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int ans=INT_MIN;
        int n=heights.size();

        //because we have to go to the left only till the prevssmaller element and same for the right direction
        vector<int>nextsmaller(n);
        vector<int>prevsmaller(n);

        solve1(nextsmaller,heights,n);
        solve2(prevsmaller,heights,n);

        
        
        for(int i=0;i<n;i++){

            //if it is then no next value will be smaller so take till the end okk
            if(nextsmaller[i]==-1){
                nextsmaller[i]=n;
            }
            int length=heights[i];
            int breadth=nextsmaller[i]-prevsmaller[i]-1;

            int area=breadth*length;
            ans=max(ans,area);
        }
        return ans;
    }
    int maxArea(vector<vector<int>> &mat) {
        // Your code here
        int n=mat.size();
        int m=mat[0].size();
        
        int ans=-1;
        
        vector<int>v(m,0);
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                int sum=v[j]+mat[i][j];
                if(mat[i][j]==0){
                    v[j]=0;
                    continue;
                }
                v[j]=sum;
            }
            

            int possible_ans=largestRectangleArea(v);
            ans=max(ans,possible_ans);
        }
        
        return ans;
    }
};

listen this ques is totally similar to max area in the histogram okk so just convert it to that ques 
and if the base contains 0 then make the entire histogram 0 okkk

t.c:-O(n*m) and s.c:-O(m)
