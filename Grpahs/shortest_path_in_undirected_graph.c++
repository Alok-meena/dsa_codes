Problem statement
The city of Ninjaland is analogous to the unweighted graph. The city has ‘N’ houses numbered from 1 to ‘N’ respectively and are
connected by M bidirectional roads. If a road is connecting two houses ‘X’ and ‘Y’ which means you can go from ‘X’ to ‘Y’ or ‘Y’ to ‘X’.
It is guaranteed that you can reach any house from any other house via some combination of roads. Two houses are directly connected by at max one road.

A path between house ‘S’ to house ‘T’ is defined as a sequence of vertices from ‘S’ to ‘T’. Where starting house is ‘S’ and the ending house is ‘T’ and there is
a road connecting two consecutive houses. Basically, the path looks like this: (S , h1 , h2 , h3 , ... T). you have to find the shortest path from ‘S’ to ‘T’.

For example
In the below map of Ninjaland let say you want to go from S=1 to T=8, the shortest path is (1, 3, 8). You can also go from S=1 to T=8  via (1, 2, 5, 8)
or (1, 4, 6, 7, 8) but these paths are not shortest.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 100
2 <= N <= 10 ^ 3
1 <= M <= min( N *(N - 1) / 2 , 1000 )
1 <= S, T <= N

Time Limit: 1 sec
Sample input 1 :
1
4 4
1 4
1 2
2 3
3 4
1 3
Sample Output 1 :
( 1 , 3 , 4 )


#include <unordered_map>
#include <queue>
#include <list>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	//create adjacency list
	unordered_map<int,list<int>>adjlist;

	for(int i=0;i<m;i++){
		int u=edges[i].first;
		int v=edges[i].second;

		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}

	unordered_map<int,bool>visited;
	unordered_map<int,int>parent;

	visited[s]=true;
	parent[s]=-1;
	queue<int>q;
	q.push(s);

	while(!q.empty()){
		int front=q.front();
		q.pop();

		for(auto i:adjlist[front]){
			if(!visited[i]){
				visited[i]=true;
				parent[i]=front;
				q.push(i);
			}
		}
	}

  //yha tk bs simple bfs kiya hai aor hmara motive that parent ko create karna jo ho gya hai aor ab ham target node se backtrack krke source node pe jayenge 
  //aor ise reverse krke return kr denge aor yhi hmara answer hoga
	int currentnode=t;
	vector<int>ans;
	ans.push_back(currentnode);

	while(currentnode!=s){
		currentnode=parent[currentnode];
		ans.push_back(currentnode);
	}

	reverse(ans.begin(),ans.end());
	return ans;
  //aor ager iski jagah lenght bhejni hoti to edge length 1 consider krke backtrack krte time count=0 leke ++ krte rhte
	
}


Time Complexity
O( N + M ), where N is the number of nodes and M is the number of edges. 

 

The Time Complexity required for the BFS traversal of a graph with N nodes and M edges is O( N + M ). Hence, the overall Time Complexity is O(N + M).

Space Complexity
O( N + M ),//ese to O(n) thi but ajdlist ko consider krke n+m aayi hai ookkk
where N is the number of nodes and M is the number of edges.

 

Adjacency List required to maintain the graph requires O(N+M) space. Hence, the overall Space Complexity is O( N + M ).
