
Code
Testcase
Testcase
Test Result
210. Course Schedule II
Solved
Medium
Topics
Companies
Hint
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.







class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        int n=numCourses;
        vector<int> adj[n];

        for(int i=0;i<p.size();i++){
           //and given [1,0] so to take course 1 course 0 must be completed so for this p[i][1] is dependent on p[i][0] alright so build accordingly
            adj[p[i][1]].push_back(p[i][0]);
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

       //mtlb ager cycle hai to return kro empty topo sort o/w return the ans of toposort
        if(ans.size()!=n) return {};


        return ans;
    }
};

same code just have to return toposort but if there is a cycle return emtpy ans
