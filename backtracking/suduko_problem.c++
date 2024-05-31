You have been given a 9x9 2d integer matrix 'MAT' representing a Sudoku puzzle.
The empty cells of the Sudoku are filled with zeros, and the rest of the cells are filled with integers from 1 to 9.
Your task is to fill all the empty cells such that the final matrix represents a Sudoku solution.

Note:
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-grids of the grid.

You can also assume that there will be only one sudoku solution for the given matrix.







#include <bits/stdc++.h> 


bool issafe(int row,int col,vector<vector<int>>&board,int val){
    int n=board.size();
    for(int i=0;i<n;i++){
        //row check
        if(board[row][i]==val){
            return false;
        }

        //col checkj
        if(board[i][col]==val){
            return false;
        }

        //checking 3x3 matrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>&board){

    int n=board[0].size();

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){

            //cell empty
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                   if(issafe(row,col,board,val)){
                        board[row][col]=val;
                        //recursive call
                        bool further_ans_possible=solve(board);
                        if(further_ans_possible){
                           return true;
                        }
                        else{
                            //backtrack
                           board[row][col]=0;
                       }
                   }
                }
                //to ager uper me se koi bhi condition true nhi hui hai to ham soln nikal hi nhi skte hai so return false
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}













Time Complexity
O(9^K),  Where ‘K’ is the number of empty cells in the given 2d matrix.

 

As we are trying all the numbers from 1 to 9 for every empty cell, our time complexity is exponential and quite high.

Space Complexity
O(1), i.e., constant space complexity.

 

In the worst-case scenario, our recursion stack can grow maximum till size 9*9 = 81, which is constant.
