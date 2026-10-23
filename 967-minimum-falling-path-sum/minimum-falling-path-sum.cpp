class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: First row
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill the DP table row by row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int up = matrix[i][j] + dp[i - 1][j];

                int leftdig = INT_MAX;
                if (j > 0) {
                    leftdig = matrix[i][j] + dp[i - 1][j - 1];
                }

                int rightdig = INT_MAX;
                if (j < m - 1) {
                    rightdig = matrix[i][j] + dp[i - 1][j + 1];
                }

                dp[i][j] = min(up, min(leftdig, rightdig));
            }
        }

        // Find the minimum value in the last row
        int mini = INT_MAX;

        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[n - 1][j]);
        }

        return mini;
    }
};
