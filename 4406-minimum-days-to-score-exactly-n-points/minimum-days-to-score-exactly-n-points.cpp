class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int ans = 1e9;

        // Take a streak of k days
        for (int k = 1; k * (k + 1) / 2 <= n; k++) {

            int points = k * (k + 1) / 2;

            if (points == n) {
                ans = min(ans, k);
            }
            else {
                // k earning days + 1 skip + remaining streak
                ans = min(ans, k + 1 + solve(n - points, dp));
            }
        }

        return dp[n] = ans;
    }

    int minDays(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};