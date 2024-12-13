37. Sudoku Solver
Solved
Hard
Topics
Companies
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.








class Solution {
public:
    bool isvalid(vector<vector<char>>&v,int row,int col,char val){

    //validate row;
    for(int j=0;j<9;j++){
        if(v[row][j]==val){
            return false;
        }
    }

    //validate column;
    for(int i=0;i<9;i++){
        if(v[i][col]==val){
            return false;
        }
    }

    //validate 3X3 matrix

    int new_row=(3*(row/3));
    int new_col=(3*(col/3));

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(v[i+new_row][j+new_col]==val){
                return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<char>>&v){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(v[i][j]!='.') continue;

            for(char k='1';k<='9';k++){
                
                if(isvalid(v,i,j,k)){
                    v[i][j]=k;
                    if(solve(v)){
                        return true;
                    }
                    v[i][j]='.';
                }
            }
            return false;
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


t.c:-O(9^n) or O(9^9) s.c:-O(1)



#include <bits/stdc++.h>
using namespace std;


bool isvalid(vector<vector<int>>&v,int row,int col,int val){

    //validate row;
    for(int j=0;j<9;j++){
        if(v[row][j]==val){
            return false;
        }
    }

    //validate column;
    for(int i=0;i<9;i++){
        if(v[i][col]==val){
            return false;
        }
    }

    //validate 3X3 matrix

    int new_row=(3*(row/3));
    int new_col=(3*(col)/3);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(v[i+new_row][j+new_col]==val){
                return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<int>>&v){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(v[i][j]!=0) continue;

            for(int k=1;k<=9;k++){
                
                if(isvalid(v,i,j,k)){
                    v[i][j]=k;
                    if(solve(v)){
                        return true;
                    }
                    v[i][j]=0;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> sudoku = {
                                    {5, 3, 0, 0, 7, 0, 0, 0, 0},
                                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                    {0, 0, 0, 0, 8, 0, 0, 7, 9}
                                };

    solve(sudoku);

    for(auto i:sudoku){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    

}
