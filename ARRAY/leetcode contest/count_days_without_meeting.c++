3169. Count Days Without Meetings
Solved
Medium
Topics
Companies
Hint
You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.

 

Example 1:

Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

Output: 2

Explanation:

There is no meeting scheduled on the 4th and 8th days.

Example 2:

Input: days = 5, meetings = [[2,4],[1,3]]

Output: 1

Explanation:

There is no meeting scheduled on the 5th day.

Example 3:

Input: days = 6, meetings = [[1,6]]

Output: 0

Explanation:

Meetings are scheduled for all working days.



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;

        sort(intervals.begin(),intervals.end());

        int start=intervals[0][0];
        int end=intervals[0][1];

        
        int n=intervals.size();

        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
            }
            else{
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        
        //adding last interval as it will not be compared and it will also be stored in start and end 
        ans.push_back({start,end});
        return ans;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>>ans=merge(meetings);
        int count=0;
        if(ans.empty()) return days;

        count+=(ans[0][0]-1);
        if(ans.size()==1){
            count+=(days-ans[0][1]);
            return count;
        }
        for(int i=1;i<ans.size();i++){
            count+=(ans[i][0]-ans[i-1][1]-1);
        }
        count += days - ans.back()[1];

        return count;
    }
};

nothing first of all we just merged the intervals alright and then counting days not included before start and after end 
