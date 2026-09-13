// class Solution {
// public:
//     int solve(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {

//         // Out of bounds
//         if(row < 0 || col < 0) {
//             return 0;
//         }

//         // Current cell is an obstacle
//         if(obstacleGrid[row][col] == 1) {
//             return 0;
//         }

//         // Reached starting cell
//         if(row == 0 && col == 0) {
//             return 1;
//         }
//         if(dp[row][col] != -1){
//             return dp[row][col];
//         }
//         int left = solve(row, col - 1, obstacleGrid,dp);

//         int up = solve(row - 1, col, obstacleGrid,dp);

//         return dp[row][col] =  left + up;
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(n - 1, m - 1, obstacleGrid,dp);
//     }
// };

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Starting cell
        if(obstacleGrid[0][0] == 1)
            return 0;

        dp[0][0] = 1;

        // First column
        for(int i = 1; i < n; i++) {

            if(obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i-1][0];
            }
        }

        // First row
        for(int j = 1; j < m; j++) {

            if(obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j-1];
            }
        }

        // Remaining cells
        for(int i = 1; i < n; i++) {

            for(int j = 1; j < m; j++) {

                // If obstacle, no path
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    int left = dp[i][j-1];
                    int up = dp[i-1][j];

                    dp[i][j] = left + up;
                }
            }
        }

        return dp[n-1][m-1];
    }
};