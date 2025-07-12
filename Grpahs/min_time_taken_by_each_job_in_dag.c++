Minimum time taken by each job to be completed given by a Directed Acyclic Graph
Difficulty: MediumAccuracy: 66.57%Submissions: 7K+Points: 4
Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by job to be completed where each Job takes unit time to get completed.

Example 1:

Input:
N=10
M=13
edges[]={{1,3},{1,4},{1,5},{2,3},{2,8},{2,9},{3,6},{4,6},{4,8},{5,8},{6,7},{7,8},{8,10}}
Output:
time[]={1,1,2,2,2,3,4,5,2,6 }
Explanation:
Start jobs 1 and 2 at the beginning and complete them at 1 unit of time. 
Since, all the jobs on which need to be completed before the jobs 3, 4, 5, and 9 are completed. So, we can start these jobs at 1st unit of time and complete these at 2nd unit of time after the completion of the dependent Job.
Similarly, 
Job 6 can only be done after the 3rd and 4th jobs are done. So, start it at the 2nd unit of time and complete it at the 3rd unit of time.
Job 7 can only be done after job 6 is done. So, you can start it at the 3rd unit of time and complete it at the 4th unit of time.
Job 8 can only be done after the 4th, 5th, and 7th jobs are done. So, start it at the 4th unit of time and complete it at the 5th unit of time.
Job 10 can only be done after the 8th job is done. So, start it at the 5th unit of time and complete it at the 6th unit of time.
Example2:

Input:
N=7
M=7
edges[]={{1,2},{2,3},{2,4},{2,5},{3,6},{4,6},{5,7}}
Output:
time[]={1,2,3,3,3,4,4}
Explanation:
Start Job 1 at the beginning and complete it at 1st unit of time.
Job 2 can only be done after 1st Job is done. So, start it at 1st unit of time and complete it at 2nd unit of time.
Since, Job 3, 4, and 5 have the only dependency on the 2nd Job. So, start these jobs at the 2nd unit of time and complete these at the 3rd unit of time.
Job 6 can only be done after the 3rd and 4th Job is done. So, start it at the 3rd unit of time and complete it at the 4th unit of time.
Job 7 can only be done after the 5th Job is done. So, start it at the 3rd hour and complete it at the 4th unit of time.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function minimumTime() which takes the edge list e[] of the graph, its size number of nodes N and M the number of edges as input parameters and returns the time array.

 

Expected Time Complexity: O(V+E), where V is the number of nodes and E is the number of edges. 
Expected Auxiliary Space: O(V)

 

Constraints:
1 <= N <= 103
1<=M<=N*(N-1)/2
1<=edges[i][0],edges[i][1]<=N.







// User function Template for C++
#include <bits/stdc++.h>

class Solution {
  public:
    void dfs(int curr,stack<int>&s,vector<bool>&vis,vector<int> adj[]){
        vis[curr]=true;
        
        for(auto neigh:adj[curr]){
            if(!vis[neigh]){
                dfs(neigh,s,vis,adj);
            }
        }
        s.push(curr);
    }
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m) {
        // code here
        vector<int> adj[n+1];
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        
        stack<int>s;
        
        vector<bool>vis(n+1,false);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,s,vis,adj);
            }
        }
        
        vector<int>ans;
        vector<int>time(n+1,1);
        while(!s.empty()){
            int u=s.top();
            for(auto neigh:adj[u]){
                time[neigh]=max(time[neigh],time[u]+1);
            }
            s.pop();
        }
        
        time.erase(time.begin());
        
        return time;
        
    }
};
