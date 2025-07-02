#include<bits/stdc++.h>
using namespace std;


to dhyan se suno that we are placing the queens row by row so there is no need to check the row as it will contain only 1 queen okk
and as we are moving up to bottom so check upper left and right diagonal only okk

bool isvalid(vector<vector<int>>&board,int n,int row,int col){

  
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

bool solve(vector<vector<int>>&v,int n,int row){
    
    //it should be row==n not n-1 because then only it will be verified that 
    //queen is placed in the final row
    if(row==n){
        return true;
    }


    //here also move only cols not rows as rows will be changed in the function only
  
    for(int col=0;col<n;col++){
        if(isvalid(v,n,row,col)){
            //place
            v[row][col]=1;
            
            if(solve(v,n,row+1)){
                return true;
            }
            v[row][col]=0;

        }
    }
    return false;
}


int main() {
	
    vector<vector<int>>v={
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
    };

    int n=v.size();
    solve(v,n,0);

    for(auto i:v){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


	
	return 0;
}

t.c:- row n rows there will be n calls so n^n calls and *n for validating it 
so t.c:-O(n^n+1) and s.c:-O(n^2)



and to store all of the possible solutions

#include<bits/stdc++.h>
using namespace std;


bool isvalid(vector<vector<int>>&board,int n,int row,int col){
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

void solve(vector<vector<int>>&v,int n,vector<vector<vector<int>>>&solutions,int row){
    
    //it should be row==n not n-1 because then only it will be verified that 
    //queen is placed in the final row
    if(row==n){
        solutions.push_back(v);
        return;
    }

    for(int col=0;col<n;col++){
        if(isvalid(v,n,row,col)){
            //place
            v[row][col]=1;

	    //here we should not have to stop and have to store all possible solutions okk 
            solve(v,n,solutions,row+1);

            //bactrack
            v[row][col]=0;

        }
    }
}


int main() {
	
    vector<vector<int>>v={
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
    };

    vector<vector<vector<int>>>solutions;

    int n=v.size();
    
    solve(v,n,solutions,0);

    for(int i=0;i<solutions.size();i++){
        for(auto j:solutions[i]){
            for(auto k:j){
                cout<<k<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }


	
	return 0;
}


and to store only indices


#include<bits/stdc++.h>
using namespace std;


bool isvalid(vector<vector<int>>&board,int n,int row,int col){
    // Check column   sbse imp ye hai ki we are only placing a single queen in each row so there will be no extra queen but we have to check curr column
    // if it is selected previosly or not alright 
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

void solve(vector<vector<int>>&v,int n,vector<int>&index,vector<vector<int>>&solutions,int row){
    
    //it should be row==n not n-1 because then only it will be verified that 
    //queen is placed in the final row
    if(row==n){
        solutions.push_back(index);
        return;
    }

    for(int col=0;col<n;col++){
        if(isvalid(v,n,row,col)){
            //place
            v[row][col]=1;
            
            index.push_back(col+1);
            solve(v,n,index,solutions,row+1);

            //bactrack
            v[row][col]=0;
            index.pop_back();

        }
    }
}


int main() {
	
    vector<vector<int>>v={
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
    };

    vector<int>index;
    vector<vector<int>>solutions;

    int n=v.size();
    
    solve(v,n,index,solutions,0);

    for(auto i:solutions){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    


	
	return 0;
}
