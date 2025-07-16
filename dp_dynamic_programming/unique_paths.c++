
Code
Testcase
Testcase
Test Result
62. Unique Paths
Attempted
Medium
Topics
Companies
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


recursion

class Solution {
public:
    int solve(int m,int n,int i,int j){
        if(i==m-1 and j==n-1) return 1;

        int total=0;

        //choose right
        if(j+1<n) total+=solve(m,n,i,j+1);

        //choose down
        if(i+1<m) total+=solve(m,n,i+1,j);

        return total;


    }
    int uniquePaths(int m, int n) {
        return solve(m,n,0,0);
    }
};

t.c:-O(2^m*n) and s.c:-O(m+n)


memorization

class Solution {
public:
    int solve(int m,int n,int i,int j,vector<vector<int>>&dp){
        if(i==m-1 and j==n-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int total=0;

        //choose right
        if(j+1<n) total+=solve(m,n,i,j+1,dp);

        //choose down
        if(i+1<m) total+=solve(m,n,i+1,j,dp);

        return dp[i][j]=total;


    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,0,0,dp);
    }
};

t.c:-O(n*m) and s.c:-O(n*m)+O(n+m)
tabulation :

int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,1)); //set all with 1 to set the last row and column with 1 alright 
        dp[m-1][n-1]=1;

        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int total=0;

                //choose right
                total+=dp[i][j+1];

                //choose down
                total+=dp[i+1][j];

                dp[i][j]=total;
            }
        }
        return dp[0][0];
    }


we have to do this 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for (int i = 0; i < m; i++) dp[i][n - 1] = 1; // last column
        for (int j = 0; j < n; j++) dp[m - 1][j] = 1; // last row


        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                //down
                int total=0;
                total+=dp[i+1][j];

                //right
                total+=dp[i][j+1];

                dp[i][j]=total;
            }
        }
        return dp[0][0];
    }
};

space optimization t.c:-O(same) and s.c:-O(n)

int uniquePaths(int m, int n) {
        vector<int>prev(n,1);

        for(int i=m-2;i>=0;i--){
            vector<int>curr(n,1);
            for(int j=n-2;j>=0;j--){
                curr[j]=curr[j+1]+prev[j];
            }
            prev=curr;
        }
        return prev[0];
    }


int uniquePaths(int m, int n) {
    vector<int> next(n, 1);  // last row: all paths = 1

    for (int i = m - 2; i >= 0; i--) {
        vector<int> curr(n, 0);  // current row
        for (int j = n - 2; j >= 0; j--) {
            curr[j] = curr[j + 1] + next[j];  // right + down
        }
        next = curr;
    }

    return next[0];
}


use this above code


💡 Why curr[j] = curr[j+1] + prev[j] Works
When using 1D DP, we only store one row at a time, so:

curr[j] represents dp[i][j] (the current row we are filling).
curr[j+1] represents dp[i][j+1] (moving right in the same row).
prev[j] represents dp[i+1][j] (the next row in original DP).

This is because:

curr[j+1] corresponds to dp[i][j+1] (right move).
prev[j] corresponds to dp[i+1][j] (down move).

We maintain:

prev[] = last computed row (which represents dp[i+1][j]).
curr[] = current row being computed (which represents dp[i][j]).

where:

curr[j+1] is the right move (dp[i][j+1]).
prev[j] is the down move (dp[i+1][j]).



📌 Example Walkthrough (m = 3, n = 3)
We start with a 2D DP table:

sql
Copy
Edit
1  1  1
1  ?  ?
1  1  1  <- Base case: Last row is all 1s (only one way to reach the end)
1️⃣ Filling the second-last row (i = 1)
Using curr[j] = curr[j+1] + prev[j]:

sql
Copy
Edit
prev = [1, 1, 1]  // Last row
curr[2] = 1       // Last column
curr[1] = curr[2] + prev[1] = 1 + 1 = 2
curr[0] = curr[1] + prev[0] = 2 + 1 = 3
Updated prev:

ini
Copy
Edit
prev = [3, 2, 1]
2️⃣ Filling the first row (i = 0)
sql
Copy
Edit
curr[2] = 1       // Last column
curr[1] = curr[2] + prev[1] = 1 + 2 = 3
curr[0] = curr[1] + prev[0] = 3 + 3 = 6
Final prev:

ini
Copy
Edit
prev = [6, 3, 1]
✅ Final Answer
prev[0] = 6, which is the number of unique paths.

⏳ Time & Space Complexity
Approach	Time Complexity	Space Complexity
2D DP	O(m × n)	O(m × n)
1D DP	O(m × n)	O(n)
🚀 Final Takeaway
The key transformation:

Copy
Edit
dp[i][j] = dp[i][j+1] + dp[i+1][j]
↓
curr[j] = curr[j+1] + prev[j]
curr[j+1] = right move (dp[i][j+1]).
prev[j] = down move (dp[i+1][j]).
This way, we reuse memory efficiently while computing row by row.

Hope this clears it up! 🚀🔥
