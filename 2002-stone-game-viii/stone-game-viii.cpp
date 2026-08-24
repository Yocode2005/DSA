class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Convert stones into prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // dp represents the maximum score difference
        // we can achieve from the current state.
        int dp = stones[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, stones[i] - dp);
        }

        return dp;
    }
};