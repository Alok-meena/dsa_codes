Cut Off Trees for Golf Event
You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:

0 means the cell cannot be walked through.
1 represents an empty cell that can be walked through.
A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.

You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).

Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.

Note: The input is generated such that no two trees have the same height, and there is at least one tree needs to be cut off.

 

Example 1:


Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
Output: 6
Explanation: Following the path above allows you to cut off the trees from shortest to tallest in 6 steps.
Example 2:


Input: forest = [[1,2,3],[0,0,0],[7,6,5]]
Output: -1
Explanation: The trees in the bottom row cannot be accessed as the middle row is blocked.
Example 3:

Input: forest = [[2,3,4],[0,0,5],[8,7,6]]
Output: 6
Explanation: You can follow the same path as Example 1 to cut off all the trees.
Note that you can cut off the first tree at (0, 0) before making any steps.
 

Constraints:

m == forest.length
n == forest[i].length
1 <= m, n <= 50
0 <= forest[i][j] <= 109
Heights of all trees are distinct.








  



class Solution {
public:
    // Helper function to perform BFS and return min steps from (sr, sc) to (tr, tc)
    int bfs(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
        if (sr == tr && sc == tc) return 0;

        int m = forest.size(), n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        int steps = 0;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!q.empty()) {
            int sz = q.size();
            steps++;
            for (int i = 0; i < sz; ++i) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        !visited[nr][nc] && forest[nr][nc] != 0) {
                        if (nr == tr && nc == tc) return steps;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return -1; // target not reachable
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<tuple<int, int, int>> trees; // (height, row, col)

        // Step 1: Collect all trees
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1)
                    trees.push_back({forest[i][j], i, j});
            }
        }

        // Step 2: Sort trees by height
        sort(trees.begin(), trees.end());

        int sr = 0, sc = 0, totalSteps = 0;

        // Step 3: Cut each tree in order
        for (auto &[height, tr, tc] : trees) {
            int steps = bfs(forest, sr, sc, tr, tc);
            if (steps == -1) return -1;
            totalSteps += steps;
            sr = tr;
            sc = tc;
        }

        return totalSteps;
    }
};
