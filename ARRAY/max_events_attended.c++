1353. Maximum Number of Events That Can Be Attended
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startDayi <= d <= endDayi. You can only attend one event at any time d.

Return the maximum number of events you can attend.

 

Example 1:


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
 

Constraints:

1 <= events.length <= 105
events[i].length == 2
1 <= startDayi <= endDayi <= 105






class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();

        sort(events.begin(),events.end());

        priority_queue<int,vector<int>,greater<int>>pq;

        int day=events[0][0];
        int cnt=0;
        int i=0;

        while(!pq.empty() or i<n){
            if(pq.empty()){
                day=events[i][0];
            }

            //it is used because earlier day jo khtm ho rha ahi vo lena hai ager start day same hai alright
            while(i<n and events[i][0]<=day){
                pq.push(events[i][1]);
                i++;
            }

            //if not empty then current event attend kr liya cnt++
            if(!pq.empty()){
                cnt++;
                pq.pop();
            }

            day++;

            //here if end day of a event if less than current day we cant attend so just do pop until empty
            while(!pq.empty() and pq.top()<day) pq.pop();
        }

        return cnt;
    }
};
