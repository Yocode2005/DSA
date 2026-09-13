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
// tabulation solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // If current cell is an obstacle,
                // there are 0 ways to reach it.
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }

                // Starting cell
                else if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                }

                else {
                    int up = 0;
                    int left = 0;

                    if(i > 0)
                        up = dp[i-1][j];

                    if(j > 0)
                        left = dp[i][j-1];

                    dp[i][j] = up + left;
                }
            }
        }

        return dp[n-1][m-1];
    }
};