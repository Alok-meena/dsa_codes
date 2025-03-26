2033. Minimum Operations to Make a Uni-Value Grid
Solved
Medium
Topics
Companies
Hint
You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

 

Example 1:


Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
Example 2:


Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.
Example 3:


Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
1 <= x, grid[i][j] <= 104





class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();

        if(m==1 and n==1) return 0;

        vector<int>v;
        for(auto i:grid){
            for(auto j:i) v.push_back(j);
        }

        sort(v.begin(),v.end());
        for(auto i:v){
            //here we are considering v[0] as the base and checking if the difference b/w all of the numbers is divisible by x or not if divisible then only 
            //it will be possible to reach any no. by adding or subtracting x from them alright
            if((i-v[0])%x!=0) return -1;
        }

        int tar;
        if(v.size()%2!=0){
            tar=v[v.size()/2];
        }
        else tar=v[v.size()/2];

        int operations=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==tar) continue;
            if(v[i]<tar){
                operations+=(tar-v[i])/x;
            }
            else{
                operations+=(v[i]-tar)/x;
            }
        }

        return operations;
    }
};

t.c:-O(n*m) and s.c:-O(n*m)
