207. Course Schedule
Solved
Medium
Topics
Companies
Hint
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.



means if there is cycle return false o/w true that's all




class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n=numCourses;
        vector<int> adj[n]; //ye to no. of courses ke equal size ka hi hoga

        for(int i=0;i<p.size();i++){
            adj[p[i][0]].push_back(p[i][1]);
        }

        vector<int>indegree(n,0);
        for(auto i:adj){
            for(auto j:i){
                indegree[j]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int>ans;

        while(!q.empty()){
            int front=q.front();
            q.pop();

            ans.push_back(front);

            for(auto neigh:adj[front]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }

        return ans.size()==n;
    }
};

and we can also use a 2d vector instead of this array of vectors also like this 

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n=numCourses;
        vector<vector<int>>adj(n);

        for(int i=0;i<p.size();i++){
            adj[p[i][0]].push_back(p[i][1]);
        }

        vector<int>indegree(n,0);
        for(auto i:adj){
            for(auto j:i){
                indegree[j]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int>ans;

        while(!q.empty()){
            int front=q.front();
            q.pop();

            ans.push_back(front);

            for(auto neigh:adj[front]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }

        return ans.size()==n;
    }
};

t.c:-O(v+e)
