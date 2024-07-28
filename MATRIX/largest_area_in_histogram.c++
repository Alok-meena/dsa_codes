Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.





1st: O(n^2) and s.c:-O(1)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int area=0;
        

        for(int i=0;i<n;i++){
            int leftsmaller_index=i;
            int rightsmaller_index=i;

            int currentvalue=heights[i];

            int j=i-1;
            while(j>=0 && heights[j]>=currentvalue){
                leftsmaller_index=j;
                j--;
            }
            int k=i+1;
            while(k<n && heights[k]>=currentvalue){
                rightsmaller_index=k;
                k++;
            }
            
            int width=rightsmaller_index-leftsmaller_index+1;
            int height=heights[i];
            int Area=width*height;

            area=max(area,Area);
        }

        return area;
    }
};


2:optimal using stack in O(n) and s.c:-O(n)

  class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

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

            if(rightsmaller[i]==-1){//it is for the case when all are same then widht=size of array
                rightsmaller[i]=n;
            }

            int width=rightsmaller[i]-leftsmaller[i]-1;


            int Area=width*height;

            area=max(area,Area);
        }

        return area;
    }
};

