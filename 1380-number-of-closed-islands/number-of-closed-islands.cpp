class Solution {
public:
    int m, n;

    bool dfs(vector<vector<int>>& grid, int row, int col) {

        // If we go outside the grid, the island is not closed
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return false;
        }

        // Water or an already visited cell
        if (grid[row][col] == 1) {
            return true;
        }

        // Mark the current land cell as visited
        grid[row][col] = 1;

        bool left_closed = dfs(grid, row, col - 1);
        bool right_closed = dfs(grid, row, col + 1);
        bool up_closed = dfs(grid, row - 1, col);
        bool down_closed = dfs(grid, row + 1, col);

        return left_closed && right_closed &&
               up_closed && down_closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
