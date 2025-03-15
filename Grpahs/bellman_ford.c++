#include <vector>
#include <limits.h>
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    
    //n+1 size because nodes are from 1
    vector<int>distance(n+1,1e8);//dont take int_max just take 1e8 okkkkk!!!!!!!!!!11
    
    distance[src]=0;
    
    //run n-1 times so n-1 tk hi chlaya hai 
    for(int i=0;i<n-1;i++){
        //traverse on edge list so ye loop hamne m edges ke liye chala diya
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];

            if(distance[u]!=INT_MAX and distance[u]+wt<distance[v]){
                distance[v]=distance[u]+wt;
            }
        }
    }

    //checking for negative cycle
    int flag=0;
      //traverse on edge list
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];

            if(dist[u]!=INT_MAX && distance[u]+wt<distance[v]){
                flag=1;
            }
        }
    if(flag==0){
        return 0;
    }
    return -1;//means negative cycle is present 
}


t.c:-O(n*m) because n-1 times traversal of all edges
s.c:-O(n)

o/w if we only have to return the distance without checking for negative cycle then just return the distance array directly okk

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int>distance(n+1,1e8);
    distance[src]=0;

    for(int i=0;i<n-1;i++){
        
        //traverse on edges
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];

            if(distance[u]+w<distance[v]){
                distance[v]=distance[u]+w;
            }
        }
    }


    return distance;

}
