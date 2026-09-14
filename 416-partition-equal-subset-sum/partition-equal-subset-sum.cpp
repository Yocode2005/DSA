class Solution {
public:
    bool solve(int idx, int target, vector<int>& nums,
               vector<vector<int>>& dp) {

        if (target == 0) return true;

        if (idx == 0) {
            return nums[0] == target;
        }

        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }

        // Don't take current element
        bool notTake = solve(idx - 1, target, nums, dp);

        // Take current element
        bool take = false;
        if (nums[idx] <= target) {
            take = solve(idx - 1, target - nums[idx], nums, dp);
        }

        return dp[idx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int x : nums) {
            sum += x;
        }

        // Equal partition is impossible if total sum is odd
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(n - 1, target, nums, dp);
    }
};