1353. Maximum Number of Events That Can Be Attended
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

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









brute force 

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int mini=INT_MAX;
        int maxi=INT_MIN;

        int n=events.size();

        for(int i=0;i<n;i++){
            mini=min(mini,min(events[i][0],events[i][1]));
            maxi=max(maxi,max(events[i][0],events[i][1]));
        }

        vector<int>vis(maxi+1,0);

        sort(events.begin(), events.end(), [](auto &a, auto &b){
    return a[1] < b[1];
});


        int days=0;

        for(int i=0;i<n;i++){
            for(int d=events[i][0];d<=events[i][1];d++){
                if(vis[d]==0){
                    days++;
                    vis[d]=1;
                    break;
                }
            }
        }

        return days;
    }
};

t.c:-O(n*d) where d is max day value alright


optimized : 

using priority queue


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();

        sort(events.begin(),events.end());

        priority_queue<int,vector<int>,greater<int>>pq;

        int day=events[0][0];
        int i=0;
        int count=0;//counting days
        
        while(!pq.empty() or i<n){
            if(pq.empty()){
                day=events[i][0];
            }
            while(i<n and events[i][0]<=day){
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                pq.pop();//1 event attended
                count++;
            }

            day++;

            while(!pq.empty() and pq.top()<day){
                pq.pop();
            }
        }

        return count;
    }
};

t.c:-O(nlogn) and s.c:-O(n) alright


can use dsu here 


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> parent;

    // DSU Find function with path compression
    int find(int day) {
        if (parent[day] != day) {
            parent[day] = find(parent[day]);
        }
        return parent[day];
    }

    int maxEvents(vector<vector<int>>& events) {
        // Sort events by end day (greedy)
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        // Find maximum day among all events
        int maxDay = 0;
        for (auto &event : events) {
            maxDay = max(maxDay, event[1]);
        }

        // Initialize DSU parent array
        parent.resize(maxDay + 2);
        for (int i = 0; i <= maxDay + 1; ++i) {
            parent[i] = i;
        }

        int count = 0;

        for (auto &event : events) {
            int availableDay = find(event[0]);  // Find earliest available day ≥ start
            if (availableDay <= event[1]) {
                count++;
                // Book this day by pointing it to the next available day
                parent[availableDay] = find(availableDay + 1);
            }
        }

        return count;
    }
};

t.c: O(N log N + N α(N)), where α(N) is almost constant.
