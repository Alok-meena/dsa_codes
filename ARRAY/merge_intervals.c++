Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;

        sort(intervals.begin(),intervals.end());//sorting normally so it will be on the basis of first element start

        int start=intervals[0][0];
        int end=intervals[0][1];

        
        int n=intervals.size();

        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
            }
            else{
                ans.push_back({start,end});//it can be done as only 2 columns are there
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        
        //adding last interval as it will not be compared and it will also be stored in start and end 
        ans.push_back({start,end});
        return ans;
    }
};

O(n)+O(nlogn)=O(nlogn) is the t.c and s.c:-O(n)
