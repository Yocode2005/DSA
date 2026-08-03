class Solution {
public:
    vector<int> dp;

    // Returns the maximum score difference
    // (Current Player Score - Opponent Score)
    // starting from index 'i'.
    int solve(int i, vector<int>& stoneValue) {

        int n = stoneValue.size();

        // No stones left
        if (i >= n)
            return 0;

        // Already computed
        if (dp[i] != INT_MIN)
            return dp[i];

        int take = 0;

        // Initialize with very small value
        int bestDifference = INT_MIN;

        // Try taking 1, 2, or 3 stones
        for (int k = 0; k < 3 && i + k < n; k++) {

            take += stoneValue[i + k];

            // Opponent plays optimally afterwards
            bestDifference = max(bestDifference,
                                 take - solve(i + k + 1, stoneValue));
        }

        return dp[i] = bestDifference;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        dp.assign(n, INT_MIN);

        int diff = solve(0, stoneValue);

        if (diff > 0)
            return "Alice";

        if (diff < 0)
            return "Bob";

        return "Tie";
    }
};