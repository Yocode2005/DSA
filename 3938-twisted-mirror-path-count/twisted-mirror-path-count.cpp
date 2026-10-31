class Solution {
public:
    int left = 0;
    int up = 1;
    int MOD = 1e9 + 7;

    int m, n;

    int solve(vector<vector<int>>& grid, int i, int j,
              int cameFrom, vector<vector<vector<int>>>& dp) {

        if(i >= m || j >= n) {
            return 0;
        }

        if(i == m-1 && j == n-1) {
            return 1;
        }

        if(dp[i][j][cameFrom] != -1) {
            return dp[i][j][cameFrom];
        }

        // Forced movement
        if(grid[i][j] == 1) {

            if(cameFrom == left) {
                return dp[i][j][cameFrom] =
                    solve(grid, i+1, j, up, dp);
            }
            else {
                return dp[i][j][cameFrom] =
                    solve(grid, i, j+1, left, dp);
            }
        }

        // Normal movement: Right or Down
        int totalPathCount = 0;

        totalPathCount = (
            totalPathCount +
            solve(grid, i, j+1, left, dp)
        ) % MOD;

        totalPathCount = (
            totalPathCount +
            solve(grid, i+1, j, up, dp)
        ) % MOD;

        return dp[i][j][cameFrom] = totalPathCount;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(2, -1))
        );

        return solve(grid, 0, 0, left, dp);
    }
};