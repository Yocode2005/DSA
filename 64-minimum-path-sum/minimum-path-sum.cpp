class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& dp,
              vector<vector<int>>& grid) {

        // Out of bounds
        if(i < 0 || j < 0) {
            return INT_MAX;
        }

        // Starting cell
        if(i == 0 && j == 0) {
            return grid[0][0];
        }

        // Already calculated
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = solve(i - 1, j, dp, grid);
        int left = solve(i, j - 1, dp, grid);

        return dp[i][j] = grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, -1));

        return solve(row - 1, col - 1, dp, grid);
    }
};