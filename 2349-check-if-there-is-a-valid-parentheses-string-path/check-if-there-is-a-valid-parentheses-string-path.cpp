class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Total path length must be even
        if ((m + n - 1) % 2)
            return false;

        // Start and end conditions
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        /*
            dp[i][j] = bitset of all possible balances
                      when we reach (i,j).

            Maximum balance is m+n.
        */
        vector<vector<bitset<205>>> dp(m, vector<bitset<205>>(n));

        // Process every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Starting cell
                if (i == 0 && j == 0) {
                    dp[i][j][1] = 1;
                    continue;
                }

                // Get all balances from top/left
                bitset<205> possible;

                if (i > 0)
                    possible |= dp[i - 1][j];

                if (j > 0)
                    possible |= dp[i][j - 1];

                if (grid[i][j] == '(') {
                    // '(' increases balance by 1
                    dp[i][j] = possible << 1;
                }
                else {
                    // ')' decreases balance by 1
                    dp[i][j] = possible >> 1;
                }

                // We can never have negative balance,
                // and bitset naturally removes it.
            }
        }

        // Valid if balance is exactly 0 at destination
        return dp[m - 1][n - 1][0];
    }
};