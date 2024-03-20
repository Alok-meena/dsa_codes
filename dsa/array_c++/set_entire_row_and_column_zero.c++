#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int row=matrix.size();
	int col=matrix[0].size();

	vector<pair<int,int>>ans; // to vector ke ander integer ke pair store honge jisme hm pahle ko row ka index aor doosre ko col ka index denge
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(matrix[i][j]==0){
				ans.push_back({i,j});   //jisme hm pahle ko row ka index aor doosre ko col ka index denge
			}
		}
	}

	while (!ans.empty()) {
    int rrow = ans.back().first; // to vector me pair me store h pahle me row k index doosre me col ka so to acess use .first for first and .second for 2nd
    int rcol = ans.back().second;
    ans.pop_back();

    for (int i = 0; i < row; i++) {
        matrix[i][rcol] = 0;
    }
    for (int i = 0; i < col; i++) {
        matrix[rrow][i] = 0;
    }
}


}
