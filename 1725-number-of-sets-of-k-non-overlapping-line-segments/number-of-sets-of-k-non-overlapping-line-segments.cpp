class Solution {
public:
    int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        // dp[i][0] = 1
        // If we need 0 segments, there is exactly 1 way.
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int segments = 1; segments <= k; segments++) {

            int suffix = 0;

            for (int idx = n - 2; idx >= 0; idx--) {

                // Add solve(idx + 1, segments - 1)
                suffix = (suffix + dp[idx + 1][segments - 1]) % MOD;

                // skip + take
                dp[idx][segments] =
                    (dp[idx + 1][segments] + suffix) % MOD;
            }
        }

        return dp[0][k];
    }
};