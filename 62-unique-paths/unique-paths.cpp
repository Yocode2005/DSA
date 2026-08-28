class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& dp) {
        
    //     // Starting cell
    //     if (i == 0 && j == 0)
    //         return 1;

    //     // Already calculated
    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     int up = 0;
    //     int left = 0;

    //     // Move from top
    //     if (i > 0)
    //         up = solve(i - 1, j, dp);

    //     // Move from left
    //     if (j > 0)
    //         left = solve(i, j - 1, dp);

    //     return dp[i][j] = up + left;
    // }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

       // return solve(m - 1, n - 1, dp);
       for(int row = 0;row<m;row++){
        for(int col = 0;col<n;col++){
            if(row == 0 && col == 0){
                  dp[row][col] = 1;
                continue;
            }
            int up=0;
            int left = 0;
            if(row>0){
                up = dp[row-1][col];
            }
            if(col>0){
                left = dp[row][col-1];
            }
            dp[row][col] = up + left;
            }
        }
       return dp[m-1][n-1];
    }
};