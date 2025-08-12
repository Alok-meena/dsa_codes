3378. Count Connected Components in LCM Graph
Hard
Topics
premium lock icon
Companies
Hint
You are given an array of integers nums of size n and a positive integer threshold.

There is a graph consisting of n nodes with the ith node having a value of nums[i]. Two nodes i and j in the graph are connected via an undirected edge if lcm(nums[i], nums[j]) <= threshold.

Return the number of connected components in this graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

The term lcm(a, b) denotes the least common multiple of a and b.

 

Example 1:

Input: nums = [2,4,8,3,9], threshold = 5

Output: 4

Explanation: 



 

The four connected components are (2, 4), (3), (8), (9).

Example 2:

Input: nums = [2,4,8,3,9,12], threshold = 10

Output: 2

Explanation: 



The two connected components are (2, 3, 4, 8, 9), and (12).

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
All elements of nums are unique.
1 <= threshold <= 2 * 105


brute force : O(N^2) t.c 


i tried this


class DisjointSet{
    public:
    vector<int>parent,rank;

    DisjointSet(int size){
        parent.resize(size+1);
        rank.resize(size+1,0);

        for(int i=0;i<=size;i++){
            parent[i]=i;
        }
    }

    int findUPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findUPar(parent[u]);
    }

    void unionByRank(int u,int v){
        int up=findUPar(u);
        int vp=findUPar(v);

        if(up==vp) return;

        if(rank[up]<rank[vp]){
            parent[up]=vp;
        }
        else if(rank[vp]<rank[up]){
            parent[vp]=up;
        }
        else{
            parent[vp]=up;
            rank[up]++;
        }
    }
};

class Solution {
public:
    bool lcm(int a,int b,int c){
        int hcf=1;
        int x=a,y=b;
        while(x>0 and y>0){
            if(x>y) x=x%y;
            else y=y%x;
        }

        if(x==0) hcf=y;
        else hcf=x;

        int d=(a*b);
        int val=(d)/hcf;

        return val<=c;
    }
    int countComponents(vector<int>& nums, int threshold) {
        int n=nums.size();
        DisjointSet ds(n+1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool check=lcm(nums[i],nums[j],threshold);
                if(check){
                    ds.unionByRank(i+1,j+1);
                }
            }
        }

        int cnt=0;
        for(int i=1;i<=n;i++){
            if(ds.findUPar(i)==i) cnt++;
        }
        
        return cnt;
    }
};



optimized:

class DisjointSet{
    public:
    vector<int>parent,rank;

    DisjointSet(int size){
        parent.resize(size+1);
        rank.resize(size+1,0);

        for(int i=0;i<=size;i++){
            parent[i]=i;
        }
    }

    int findUPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findUPar(parent[u]);
    }

    void unionByRank(int u,int v){
        int up=findUPar(u);
        int vp=findUPar(v);

        if(up==vp) return;

        if(rank[up]<rank[vp]){
            parent[up]=vp;
        }
        else if(rank[vp]<rank[up]){
            parent[vp]=up;
        }
        else{
            parent[vp]=up;
            rank[up]++;
        }
    }
};

class Solution {
public:
    bool lcm(int a,int b,int c){
        long long hcf=1;
        int x=a,y=b;
        while(x>0 and y>0){
            if(x>y) x=x%y;
            else y=y%x;
        }

        if(x==0) hcf=y;
        else hcf=x;

        long long d=(1LL*a*b);
        long long val=(d)/hcf;

        return val<=c;
    }
    int countComponents(vector<int>& nums, int threshold) {
        int n=nums.size();
        DisjointSet ds(threshold);
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= threshold) {
                // iterating on all multiple of nums[i]
                for(int j=nums[i]; j <= threshold; j+=nums[i]) {
                    // joining nums[i] with its multiple
                    ds.unionByRank(nums[i], j); //we have to join by values to index o/w O(n^2) t.c if we join using indices alright
                }
            }
        }

         set<int> st;
         int ans=0; // contains the parents of each nums[i]
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > threshold) ans++; // this number itself is a component
            else st.insert(ds.findUPar(nums[i]));
        }

        ans += st.size(); // number of unique parents = number of components
        // Please upvote if liked else downvote if didn't like the solution
        return ans;
    }
};


now finally it runs
