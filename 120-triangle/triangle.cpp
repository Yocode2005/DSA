class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        // dp[row][col] = minimum path sum
        // from (row, col) to the bottom
        vector<vector<int>> dp(n, vector<int>(n));

        // Base case: last row
        for (int col = 0; col < n; col++) {
            dp[n - 1][col] = triangle[n - 1][col];
        }

        // Fill from bottom to top
        for (int row = n - 2; row >= 0; row--) {

            for (int col = 0; col <= row; col++) {

                int vertically = dp[row + 1][col];
                int diagonally = dp[row + 1][col + 1];

                dp[row][col] = triangle[row][col] +
                                min(vertically, diagonally);
            }
        }

        return dp[0][0];
    }
};