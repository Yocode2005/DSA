class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // dp[i][j] = Maximum score difference the current player
        // can achieve over the opponent from subarray [i...j].
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base Case:
        // If only one number is left, the current player picks it.
        // So the score difference is nums[i].
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        // len = current length of the subarray
        for (int len = 2; len <= n; len++) {

            // Generate every subarray of length = len
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                // Option 1:
                // Pick the left element.
                // After picking nums[i], the opponent becomes the current player
                // on subarray [i+1...j].
                // Since dp stores score difference,
                // our gain = nums[i] - opponent's advantage.
                int pickLeft = nums[i] - dp[i + 1][j];

                // Option 2:
                // Pick the right element.
                int pickRight = nums[j] - dp[i][j - 1];

                // Choose the better option.
                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        // If the maximum score difference is non-negative,
        // Player 1 can win or tie.
        return dp[0][n - 1] >= 0;
    }
};