
Maximum Stone Removal
Difficulty: MediumAccuracy: 49.82%Submissions: 19K+Points: 4Average Time: 30m
Given an 2D array of non-negative integers stones[][] where stones[i] = [xi, yi] represents the location of the ith stone on a 2D plane, the task is to return the maximum possible number of stones that you can remove.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Note: Each coordinate point may have at most one stone.

Examples:

Input: stones[][] = [[0, 0], [0, 1], [1, 0], [1, 2], [2, 1], [2, 2]]
Output:5
Explanation:
One way to remove 5 stones is as follows:
1. Remove stone [2, 2] because it shares the same row as [2, 1].
2. Remove stone [2, 1] because it shares the same column as [0, 1].
3. Remove stone [1, 2] because it shares the same row as [1, 0].
4. Remove stone [1, 0] because it shares the same column as [0, 0].
5. Remove stone [0, 1] because it shares the same row as [0, 0].
Stone [0, 0] cannot be removed since it does not share any row/column with another stone still on the plane.
Input: stones[][] = [[0, 0], [0, 2], [1, 1], [2, 0], [2, 2]]
Output: 3
Explanation: 
One way to remove 3 stones is as follows:
1. Remove stone [2, 2] because it shares the same row as [2, 0].
2. Remove stone [2, 0] because it shares the same column as [0, 0].
3. Remove stone [0, 2] because it shares the same row as [0, 0].
Stones [0, 0] and [1, 1] cannot be removed since they do not share any row/column with another stone still on the plane.
Constraints:

1 <= stones.size() <=1000
0 <= x[i], y[i]<= 104
No two stones are at same position.








brute force by bfs 

t.c:-O(n^2) and same s.c 


class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Building the graph
        vector<int> adj[n];  // Adjacency list
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        // Visited array
        vector<int> vis(n, 0);
        int components = 0;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                components++;
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for(auto &nbr : adj[node]) {
                        if(!vis[nbr]) {
                            vis[nbr] = 1;
                            q.push(nbr);
                        }
                    }
                }
            }
        }
        
        return n - components;
    }
};


by dsu


class DisjointSet{
    public:
    vector<int>rank,parent,size;

    DisjointSet(int size){
        rank.resize(size+1,0);
        parent.resize(size+1);
        this->size.resize(size+1,1);
        for(int i=0;i<=size;i++){
            parent[i]=i;
        }
    }

    //finding ultimate parent and  path compression
    int findUPar(int u){
        if(u==parent[u]) return u;
        return parent[u]=findUPar(parent[u]);
    }

    void unionByRank(int u,int v){
        int up=findUPar(u);
        int vp=findUPar(v);

        //if belong to same compo with same ultimate paretn then no need to do their unio alright
        if(up==vp) return;

        int rank_up=rank[up];
        int rank_vp=rank[vp];

        if(rank_up<rank_vp){
            parent[up]=vp;
        }
        else if(rank_vp<rank_up){
            parent[vp]=up;
        }
        else{
            parent[vp]=up;
            rank[up]++;
        }
    }

    void unionBySize(int u,int v){
        int up=findUPar(u);
        int vp=findUPar(v);

        //if belong to same compo with same ultimate paretn then no need to do their unio alright
        if(up==vp) return;

        int size_up=size[up];
        int size_vp=size[vp];

        if(size_up<size_vp){
            parent[up]=vp;
            size[vp]+=size[up];
        }
        else{
            parent[vp]=up;
            size[up]+=size[vp];
        } //else me equal ho ya chota koi sa bhi lga skte to ye lga diya alright
    }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxrow=0;
        int maxcol=0;
        
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        
        DisjointSet ds(maxrow+maxcol+2);
        
        for(int i=0;i<n;i++){
            int noderow=stones[i][0];
            int nodecol=stones[i][1]+maxrow+1;
            
            ds.unionBySize(noderow,nodecol);
        }
        
        int cnt=0;

        //and to get unique parents with size 1 we know if parent[i]==i and size is greater than 1 then just take it 
        
        for(int i=0;i<(maxrow+maxcol+2);i++){
            if(ds.parent[i]==i && ds.size[i]>1){ //here we are checking size is greater than 1 and unionbysize is used both should be same but do use the last 
            //code approach only alright
                cnt++;
            }
        }
        
        return n-cnt;
    }
};



t.c:-O(N*alpha(n)) alright



works both by rank and size as here we are not supposed to return the specific sizes of compo right



class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxrow=0;
        int maxcol=0;
        
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        
        DisjointSet ds(maxrow+maxcol+2);
        
        for(int i=0;i<n;i++){
            int noderow=stones[i][0];
            int nodecol=stones[i][1]+maxrow+1;
            
            ds.unionByRank(noderow,nodecol);
        }
        
        int cnt=0;
        
        for(int i=0;i<(maxrow+maxcol+2);i++){
            if(ds.parent[i]==i && ds.rank[i]>0){ //here also unionbyrank is called and rank is used so both should be same alright
                cnt++;
            }
        }
        
        return n-cnt;
    }
};


2nd time

 int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxrow=0;
        int maxcol=0;
        

        for(int i=0;i<stones.size();i++){
            maxrow=max(maxrow,stones[i][0]);
            maxcol=max(maxcol,stones[i][1]);
        }
        
        DisjointSet ds(maxrow+maxcol+2);
        
        for(int i=0;i<n;i++){
            int row=stones[i][0];
            int col=stones[i][1]+maxrow+1;
            
            //this is not mandatory it is handled in the union operation already okk 
            //if(ds.findUPar(row)==ds.findUPar(col)) continue;
            
            ds.unionByRank(row,col);
        }
        
        int connected_compo=0;
        
        for(int i=0;i<(maxrow+maxcol+2);i++){
            if(ds.parent[i]==i and ds.rank[i]>0) connected_compo++;
        }
        
        return n-connected_compo;
    }

if the compo's counting part giving wrong ans then count only for those whose union is done and also unique ones only alright like below :::


set<int>v;
        
        for(int i=0;i<n;i++){
            int row=stones[i][0];
            int col=stones[i][1]+maxrow+1;
            

            if(ds.findUPar(row)==ds.findUPar(col)) continue;
            
            ds.unionByRank(row,col);
            v.insert(row);
            v.insert(col);
        }
        
        int connected_compo=0;
        
        for(auto i:v) if(ds.findUPar(i)==i) connected_compo++;
        
        // for(int i=0;i<(maxrow+maxcol+2);i++){
        //     if(ds.parent[i]==i and ds.rank[i]>0) connected_compo++;
        // }
        
        return n-connected_compo;
    } ookkk
