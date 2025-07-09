








// User function Template for C++
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
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DisjointSet ds(V);
        
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    ds.unionByRank(i, j);
                }
            }
        }

        int cnt=0;
        for(int i=0;i<V;i++) if(ds.parent[i]==i) cnt++;
        return cnt;

        the above one is perfect alright

        it is also okk but can use above one also if parent[i]=i then do cnt++ because we are just counting each compo parent alright


        this below one is done for path compression means if all nodes ultimate parent is on updated then it wiil be by this 
        
        for(int i=0;i<V;i++) ds.parent[i]=ds.findUPar(i);

        set<int>s(ds.parent.begin(),ds.parent.begin()+V);
        return s.size();

      or can do

        set<int>s;
        for(int i=0;i<V;i++){
            s.insert(ds.findUPar(i));
        }
        return s.size();
        
    }
};
