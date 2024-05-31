The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that no two queens attack each other.

Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.

Two queens on the same chessboard can attack each other if any of the below condition satisfies:  
1. They share a row. 
2. They share a column. 
3. They share a diagonal. 





#include <bits/stdc++.h> 

#include <vector>

bool issafe(int row,int col,vector<vector<int>>&board,int n){
	int x=row;
	int y=col;
    
	//we are filling left to right so no need to check on the right side only check to the left side
	//ham har bar har column me 1 queen place kr rhe hai so no need to check column
	//aor right aor right side ka diagonal bhi check nhi krenge
	//checking for same row
	while(y>=0){
		if(board[x][y]==1){
			return false;
		}
		y--;//to row check krne me row same hi hai bs col decrement ho rha hai
	}

	//check for diagonal left up
	x=row;
	y=col;
	while(x>=0 && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}

	//check for diagonal left down
	x=row;
	y=col;
	while(x<n && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x++;
		y--;
	}

	//aor ager uper me se koi bhi condition true nhi hai to 
	return true;
}
void addsolution(vector<vector<int>>&board,vector<vector<int>>&ans,int n){
	vector<int>temp;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
}
void solve(int col,int n,vector<vector<int>>&ans,vector<vector<int>>&board){
	//base case
	if(col==n){
		addsolution(board,ans,n);
		return;
	}

	//solve 1 case and rest recusion will take care

	for(int row=0;row<n;row++){
		if(issafe(row,col,board,n)){
			//if placing queen is safe
			board[row][col]=1;
			solve(col+1,n,ans,board);
			//bactrack and make that queen 0
			board[row][col]=0;
		}
	}
}
vector<vector<int>> nQueens(int n)
{

	vector<vector<int>>board(n , vector<int>(n,0));//board initialized with 0
	vector<vector<int>>ans;

	solve(0,n,ans,board);
	return ans;
}


Time Complexity
O(N ^ N),  where ‘N’ is the number of queens. 

There are N possibilities to place the first queen, N possibilities to place the second queen, 
N possibilities to place the third queen, and so on. Thus, the final time complexity is O(N ^ N). 

Space Complexity
O(N * N), where ‘N’ is the number of queens in the configuration. 



after using hashmaps------
  Time Complexity
O(N!), where ‘N’ is the number of queens and ‘!’ represents factorial.

There are N possibilities to put the first queen, not more than N * (N - 2) to put the second one,
not more than N* (N - 2) * (N - 4) for the third one, and so on. Thus, the final complexity is O(N!).

Space Complexity
O(N * N), where ‘N’ is the number of queens in the configuration. 
