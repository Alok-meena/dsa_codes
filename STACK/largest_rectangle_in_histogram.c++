84. Largest Rectangle in Histogram
Solved
Hard
Topics
Companies
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104


1) brute force solution::::::::::::::::::---------



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=INT_MIN;
        int n=heights.size();
        
        for(int i=0;i<n;i++){
            int left=i;
            int right=i;

           //here we have to used left-1 like this so that left will not change and we will check this value also okkk

            while(left-1>=0 and heights[left-1]>=heights[i]){
                left--;
            }
            while(right+1<n and heights[right+1]>=heights[i]){
                right++;
            }

            int length=right-left+1;
            int area=heights[i]*length;
            ans=max(ans,area);
            cout<<area<<" ";
        }
        return ans;
    }
};


t.c:-O(N^2) and s.c:-O(1)


2) optimized

class Solution {
public:
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
            int breadth=nextsmaller[i]-prevsmaller[i]-1; //to suno hame only next smaller ke pahle index tk ki length chahihe okk that's why -1 kiya u can
            //check by doing dry run okk

            int area=breadth*length;
            ans=max(ans,area);
        }
        return ans;
    }
};

t.c:-O(n) and s.c:-O(n)

