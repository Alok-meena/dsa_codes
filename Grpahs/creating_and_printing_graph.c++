Problem statement
You are given an undirected graph of 'N' nodes and 'M' edges. Your task is to create the graph and print the adjacency list of the graph. It is guaranteed that all the edges are unique, i.e., if there is an edge from 'X' to 'Y', then there is no edge present from 'Y' to 'X' and vice versa. Also, there are no self-loops present in the graph.



In graph theory, an adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a vertex in the graph.



For Example:
If 'N' = 3 and edges = {{2,1}, {2,0}}.

So, the adjacency list of the graph is stated below.
0 → 2
1 → 2
2 → 0 → 1

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.

    //here insted of unordered_map<int,list<int>> we used vector<vector<int>>
    vector<vector<int>>ans(n);
    

    // Idhr hmlog sbko khudse conect kr rahe hai matlab manle 1st node 
    //sbse pelhe khudse connect hoga tbna aage jaayga wahi wahi hmlog self node add kr rahe hai\

    *** this is used because self loops are also present in the graph
    for(int i=0;i<n;i++){
        ans[i].push_back(i);
    }


     // Idhr dekh isme hmlog do values aara input me usko dekhre u hogya pelha value v hogya dusra
     // value dono ka number me matric me hmlog connection banare hai u ka v ke saath v ka u ke saath
    for(int i=0;i<m;i++){

        //because in vector<vector<int>> edges only two edges are present because it is in that format in the vector
        int u=edges[i][0];//because jo edges hai vector<vector<int>> me store hai aor pahle me u and doosre me v to pahli value ke liye (*** column 0 me u hai and i is used to access all the values
        int v=edges[i][1];//and here i is used and v value is present in 1st column

        //2 column hai u and v ke and multiple rows hai so for u to access all rows value use i then 0 for first column similarly for v [i][1] to access all the
        //values of 2nd column ex:- v

        // Assuming the graph is undirected, add edges in both directions

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    return ans;
}

