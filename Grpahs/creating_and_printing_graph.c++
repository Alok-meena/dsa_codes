

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<vector<int>>ans(n);
    

    // Idhr hmlog sbko khudse conect kr rahe hai matlab manle 1st node 
    //sbse pelhe khudse connect hoga tbna aage jaayga wahi wahi hmlog self node add kr rahe hai
    for(int i=0;i<n;i++){
        ans[i].push_back(i);
    }


     // Idhr dekh isme hmlog do values aara input me usko dekhre u hogya pelha value v hogya dusra
     // value dono ka number me matric me hmlog connection banare hai u ka v ke saath v ka u ke saath
    for(int i=0;i<m;i++){
        int u=edges[i][0];//because jo edges hai vector<vector<int>> me store hai aor pahle me u and doosre me v to pahli value ke liye (*** column 0 me u hai and i is used to access all the values
        int v=edges[i][1];//and here i is used and v value is present in 1st column

        // Assuming the graph is undirected, add edges in both directions

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    return ans;
}

