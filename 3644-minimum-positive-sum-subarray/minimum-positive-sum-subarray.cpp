class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();
        int ans = INT_MAX;

        // Try every starting index
        for (int i = 0; i < n; i++) {

            int sum = 0;

            // Extend the subarray
            for (int j = i; j < n; j++) {

                sum += nums[j];

                int len = j - i + 1;

                // Check if length is within [l, r]
                if (len >= l && len <= r) {

                    // We only care about positive sums
                    if (sum > 0)
                        ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};