You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.

Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph.

Example:

Input:
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6

In the given input, the number of vertices is 4, and the number of edges is 5.

In the input, following the number of vertices and edges, three numbers are given. The first number denotes node ‘X’, the second number denotes node ‘Y’ and the third number denotes the distance between node ‘X’ and ‘Y’.

As per the input, there is an edge between node 0 and node 1 and the distance between them is 5.

The vertices 0 and 2 have an edge between them and the distance between them is 8.
The vertices 1 and 2 have an edge between them and the distance between them is 9.
The vertices 1 and 3 have an edge between them and the distance between them is 2.
The vertices 2 and 3 have an edge between them and the distance between them is 6.
Note:

1. There are no self-loops(an edge connecting the vertex to itself) in the given graph.

2. There can be parallel edges i.e. two vertices can be directly connected by more than 1 edge.


#include <bits/stdc++.h> 
#include <vector>
#include <limits.h>
#include <unordered_map>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    
    //create adjacency list
    unordered_map<int,list<pair<int,int>>>adjlist;

    for(int i=0;i<edges;i++){
        int v=vec[i][0];
        int u=vec[i][1];
        int weight=vec[i][2];

        adjlist[v].push_back(make_pair(u,weight));
        adjlist[u].push_back(make_pair(v,weight));
    }
    

    //creation of distance array with infinite value initially
    vector<int>distance(vertices);
    for(int i=0;i<vertices;i++){
        distance[i]=INT_MAX;
    }

    //creation of set on basis (distance,node)
    set<pair<int,int>>st;

    //initialize distance and set with source node
    distance[source]=0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        //fetch top record
        auto top=*(st.begin());

        int nodedistance=top.first;
        int topnode=top.second;

        //remove top record now
        st.erase(st.begin());

        //traverse neighbours
        for(auto neighbour:adjlist[topnode]){
            if(nodedistance+neighbour.second<distance[neighbour.first]){
                
                //finding record
                auto record=st.find(make_pair(distance[neighbour.first],neighbour.first));
                 // if record found than erase it
                if( record != st.end()){
                    st.erase(record);
                }

                //distance update
                distance[neighbour.first]=nodedistance+neighbour.second;
                //push into set
                st.insert(make_pair(distance[neighbour.first],neighbour.first));
            }
        }
        
    }
    return distance;



}

t.c: O(E log (v) )
s.c: O(E+V)
