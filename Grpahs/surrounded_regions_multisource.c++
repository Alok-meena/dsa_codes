130. Surrounded Regions
Solved
Medium
Topics
premium lock icon
Companies
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.




class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        queue<pair<int,int>>q;

        int n=grid.size();
        int m=grid[0].size();

        //left col and right col
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O') {
                q.push({i, 0});
                grid[i][0] = 'Y';  // Mark visited
            }
            if (grid[i][m - 1] == 'O') {
                q.push({i, m - 1});
                grid[i][m - 1] = 'Y';
            }
        }

        // Top and bottom rows
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 'O') {
                q.push({0, i});
                grid[0][i] = 'Y';
            }
            if (grid[n - 1][i] == 'O') {
                q.push({n - 1, i});
                grid[n - 1][i] = 'Y';
            }
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            int dirx[4]={-1,0,0,1};
            int diry[4]={0,-1,1,0};

            for(int d=0;d<4;d++){
                int newi=i+dirx[d];
                int newj=j+diry[d];

                if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj]=='O'){
                    grid[newi][newj]='Y';
                    q.push({newi,newj});
                }
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //chahe pahle y->o me ya o->y me kro dono shi h but use else if o/w curr y ko o kiya aor fir x bhi krke wrong kr doge
                if(grid[i][j]=='Y') grid[i][j]='O';
                else if(grid[i][j]=='O') grid[i][j]='X';
            }
        }
    }
};

bs kya kiya ki jo boundary ke 'O' the unhe y se mark kr diya aor uske sath valo ko bhi visit kr diya alright ab jo bche O hai unhe X kr do and Y ko O kr do
