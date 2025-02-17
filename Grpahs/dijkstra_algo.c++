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
        //very very important yha indexing 0 se hi start thi ager 1 se ho to yha niche -1 krke  kr lena
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

    // A set is a data structure that stores unique elements of the same type in a sorted order. 
    //so set's first value will be the minimum value and min value will be present at the top
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
                // If the element is found, st.find returns an iterator to the element.
                //If the element is not found, st.find returns st.end(), which is an iterator to one past the last element of the set.
                //This is a standard way in C++ to indicate that the element is not in the set. to bs ager st.end() ke equal nhi hai to erase it
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

t.c: O(E log (v) ) because we use set operations
s.c: O(E+V)

using priority queue instead of set

#include <bits/stdc++.h>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adjlist;

    for (int i = 0; i < edges; i++) {
        int v = vec[i][0];
        int u = vec[i][1];
        int weight = vec[i][2];

        adjlist[v].push_back(make_pair(u, weight));
        adjlist[u].push_back(make_pair(v, weight));
    }

    // Creation of distance array with infinite value initially
    vector<int> distance(vertices, INT_MAX);

    // Min-heap priority queue (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize distance and priority queue with source node
    distance[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        // Fetch top record
        auto top = pq.top();
        pq.pop();

        int nodedistance = top.first;
        int topnode = top.second;

        // Traverse neighbours
        for (auto neighbour : adjlist[topnode]) {
            

            if (nodedistance + neighbour.second < distance[neighbour.first]) {
                // Distance update
                distance[neighbour.first] = nodedistance + neighbour.second;
                // Push updated distance to priority queue
                pq.push(make_pair(distance[neighbour.first], neighbour.first));
            }
        }
    }
    return distance;
}



2nd time :

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<pair<int,int>> adj[vertices];

    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int>distance(vertices,INT_MAX);
    distance[source]=0;

    set<pair<int,int>>st; //node,dist because sorts based on first value okk and we need weight's here
    st.insert({0,source});

    while(st.size()){
        auto top=*st.begin();
        st.erase(st.begin());

        int currnode=top.second;
        int dist=top.first;

        for(auto neigh:adj[currnode]){
            //and isme hame dist[currnode]!=INT_MAX condition ki bhi requirement nhi hai okk as we are using set to process nodes with smalles distance 
            //it is genearally used when there are nodes which are not eachable okk
            if(dist+neigh.second<distance[neigh.first]){
                //we have to remove the distance correspoinding to this neigh.first node 
                //as if we enter this condition means that is more distance and we want latest distances
                //in our code can do dry run and u will got it 
                auto record=st.find({distance[neigh.first],neigh.first});
                //if record found remove it

                if(record!=st.end()){
                    st.erase(record);
                }

                distance[neigh.first]=dist+neigh.second;
                st.insert({distance[neigh.first],neigh.first}); //yha pe jo distance update kiya hai
                //hamne vo update karna hai okk not the neigh.second it will be wrong
            }
        }
    }

    return distance;
}
