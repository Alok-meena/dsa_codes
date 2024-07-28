Difficulty: HardAccuracy: 36.43%Submissions: 106K+Points: 8
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.



1:optimal n*m and s.c:-O(m)



class Solution{
    private:
    int largestRectangleArea(int heights[],int m) {
        int n=m;

        vector<int>leftsmaller(n);
        vector<int>rightsmaller(n);

        stack<int>s1;
        s1.push(-1);

        for(int i=n-1;i>=0;i--){
            int curr=heights[i];
            while(s1.top()!=-1 && heights[s1.top()]>=curr){
                s1.pop();
            }
            rightsmaller[i]=s1.top();
            s1.push(i);

        }
        
        stack<int>s2;
        s2.push(-1);

        

        for(int i=0;i<n;i++){
            int curr=heights[i];
            while(s2.top()!=-1 && heights[s2.top()]>=curr){
                s2.pop();
            }
            leftsmaller[i]=s2.top();
            s2.push(i);

        }
        
        int area=INT_MIN;

        for(int i=0;i<n;i++){

            int currentvalue=heights[i];
            
            // int width=rightsmaller[i]-leftsmaller[i]-1;
            int height=heights[i];

            if(rightsmaller[i]==-1){
                rightsmaller[i]=n;
            }

            int width=rightsmaller[i]-leftsmaller[i]-1;


            int Area=width*height;

            area=max(area,Area);
        }

        return area;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int heights[m]={0};
        int area=INT_MIN;

        //to basically har ek row ko bhej rhe hai and area nikal rhe fir agli row ke liye just height ko increase kr rhe hai
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==1){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            
            area=max(area,largestRectangleArea(heights,m));
        }
        
        return area;
    }
};
